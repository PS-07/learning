import path from 'path'
import readline from 'readline'
import * as grpc from '@grpc/grpc-js'
import * as protoLoader from '@grpc/proto-loader'
import { ProtoGrpcType } from './proto/random'

const PORT = 8082 
const PROTO_FILE = './proto/random.proto'

const packageDef = protoLoader.loadSync(path.resolve(__dirname, PROTO_FILE))
const grpcObj = (grpc.loadPackageDefinition(packageDef) as unknown) as ProtoGrpcType
const pb = grpcObj.pb

const client = new grpcObj.pb.Random(`0.0.0.0:${PORT}`, grpc.credentials.createInsecure())
const deadline = new Date()
deadline.setSeconds(deadline.getSeconds() + 5)

client.waitForReady(deadline, (err) => {
    if (err) {
        console.error(err)
        return
    }
    onClientReady()
})

function onClientReady() {
    // client.PingPong({message: "ping"}, (err, result) => {
    //     if (err) {
    //         console.error(err)
    //         return
    //     }
    //     console.log(result)
    // })

    // const serverStream = client.randomNumbers({maxVal: 85})
    // serverStream.on("data", (chunk) => {
    //     console.log(chunk)
    // })
    // serverStream.on("end", () => {
    //     console.log("communication ended")
    // })

    // const clientStream = client.TodoList((err, result) => {
    //     if (err) {
    //         console.error(err);
    //         return
    //     }
    //     console.log(result); 
    // })
    // clientStream.write({todo: "learn golang", status: "doing"})
    // clientStream.write({todo: "learn python", status: "done"})
    // clientStream.write({todo: "learn java", status: "doing"})
    // clientStream.write({todo: "learn rust", status: "impossible"})
    // clientStream.end()

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })

    const username = process.argv[2]
    if (!username) {
        console.error("no username, can't join chat")
        process.exit()
    }

    const metadata = new grpc.Metadata()
    metadata.set('username', username)
    
    const call = client.Chat(metadata)
    
    call.write({message: 'register'})

    call.on("data", (chunk) => {
        console.log(`${chunk.username} ==> ${chunk.message}`);
    })

    rl.on("line", (line) => {
        if (line === "quit") {
            call.end()
        } else {
            call.write({message: line})
        }
    })

}
