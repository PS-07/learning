import path from 'path'
import * as grpc from '@grpc/grpc-js'
import * as protoLoader from '@grpc/proto-loader'
import { ProtoGrpcType } from './proto/random'
import { RandomHandlers } from './proto/pb/Random'
import { TodoResponse } from './proto/pb/TodoResponse'
import { ChatRequest } from './proto/pb/ChatRequest'
import { ChatResponse } from './proto/pb/ChatResponse'

const PORT = 8082 
const PROTO_FILE = './proto/random.proto'

const packageDef = protoLoader.loadSync(path.resolve(__dirname, PROTO_FILE))
const grpcObj = (grpc.loadPackageDefinition(packageDef) as unknown) as ProtoGrpcType
const pb = grpcObj.pb

function main () {
    const server = getServer()
    server.bindAsync(`0.0.0.0:${PORT}`, grpc.ServerCredentials.createInsecure(), 
    (err, port) => {
        if (err) {
            console.log(err)
            return
        }
        console.log(`server has started on port ${port}`)
        server.start( )
    })
}

const todoList: TodoResponse = {todos: []}
const callObjByUsername = new Map<String, grpc.ServerDuplexStream<ChatRequest, ChatResponse>>()

function getServer() {
    const server = new grpc.Server()

    server.addService(pb.Random.service, {
        PingPong: (req, res) => {
            console.log(req.request)
            res(null, {message: "pong"})
        },
        RandomNumbers: (call) => {
            const { maxVal = 10 } = call.request
            console.log({maxVal})

            let runCount = 0
            let maxCount = 10
            const id = setInterval(() => {
                runCount++
                call.write({num: Math.floor(Math.random() * maxVal)})
                if (runCount >= maxCount) {
                    clearInterval(id)
                    call.end()
                }
            }, 500)
        },
        TodoList: (call, callback) => {
            call.on("data", (chunk) => {
                console.log(chunk);
                todoList.todos!.push(chunk)
            })
            call.on("end", () => {
                callback(null, {todos: todoList.todos})
            })
        },
        Chat: (call) => {
            call.on("data", (req) => {
                const username = call.metadata.get('username')[0] as string
                const msg = req.message
                console.log(username, req.message)

                for(let [uname, userCall] of callObjByUsername) {
                    if (username !== uname) {
                        userCall.write({
                            username: username,
                            message: msg
                        })
                    }
                }

                if (callObjByUsername.get(username) === undefined) {
                    callObjByUsername.set(username, call)
                }
            })
            
            call.on("end", () => {
                const username = call.metadata.get('username')[0] as string
                callObjByUsername.delete(username)
                console.log(`${username} is ending their chat session`)
                for(let [uname, userCall] of callObjByUsername) {
                    userCall.write({
                        username: username,
                        message: 'has left the chat'
                    })
                }

                call.write({
                    username: 'server',
                    message: `see you later ${username}`
                })
                call.end()
            })
        }
    } as RandomHandlers)

    return server
}

main()
