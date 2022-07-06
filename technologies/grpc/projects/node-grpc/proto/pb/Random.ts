// Original file: proto/random.proto

import type * as grpc from '@grpc/grpc-js'
import type { MethodDefinition } from '@grpc/proto-loader'
import type { ChatRequest as _pb_ChatRequest, ChatRequest__Output as _pb_ChatRequest__Output } from '../pb/ChatRequest';
import type { ChatResponse as _pb_ChatResponse, ChatResponse__Output as _pb_ChatResponse__Output } from '../pb/ChatResponse';
import type { NumberRequest as _pb_NumberRequest, NumberRequest__Output as _pb_NumberRequest__Output } from '../pb/NumberRequest';
import type { NumberResponse as _pb_NumberResponse, NumberResponse__Output as _pb_NumberResponse__Output } from '../pb/NumberResponse';
import type { PingRequest as _pb_PingRequest, PingRequest__Output as _pb_PingRequest__Output } from '../pb/PingRequest';
import type { PongResponse as _pb_PongResponse, PongResponse__Output as _pb_PongResponse__Output } from '../pb/PongResponse';
import type { TodoRequest as _pb_TodoRequest, TodoRequest__Output as _pb_TodoRequest__Output } from '../pb/TodoRequest';
import type { TodoResponse as _pb_TodoResponse, TodoResponse__Output as _pb_TodoResponse__Output } from '../pb/TodoResponse';

export interface RandomClient extends grpc.Client {
  Chat(metadata: grpc.Metadata, options?: grpc.CallOptions): grpc.ClientDuplexStream<_pb_ChatRequest, _pb_ChatResponse__Output>;
  Chat(options?: grpc.CallOptions): grpc.ClientDuplexStream<_pb_ChatRequest, _pb_ChatResponse__Output>;
  chat(metadata: grpc.Metadata, options?: grpc.CallOptions): grpc.ClientDuplexStream<_pb_ChatRequest, _pb_ChatResponse__Output>;
  chat(options?: grpc.CallOptions): grpc.ClientDuplexStream<_pb_ChatRequest, _pb_ChatResponse__Output>;
  
  PingPong(argument: _pb_PingRequest, metadata: grpc.Metadata, options: grpc.CallOptions, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  PingPong(argument: _pb_PingRequest, metadata: grpc.Metadata, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  PingPong(argument: _pb_PingRequest, options: grpc.CallOptions, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  PingPong(argument: _pb_PingRequest, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  pingPong(argument: _pb_PingRequest, metadata: grpc.Metadata, options: grpc.CallOptions, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  pingPong(argument: _pb_PingRequest, metadata: grpc.Metadata, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  pingPong(argument: _pb_PingRequest, options: grpc.CallOptions, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  pingPong(argument: _pb_PingRequest, callback: grpc.requestCallback<_pb_PongResponse__Output>): grpc.ClientUnaryCall;
  
  RandomNumbers(argument: _pb_NumberRequest, metadata: grpc.Metadata, options?: grpc.CallOptions): grpc.ClientReadableStream<_pb_NumberResponse__Output>;
  RandomNumbers(argument: _pb_NumberRequest, options?: grpc.CallOptions): grpc.ClientReadableStream<_pb_NumberResponse__Output>;
  randomNumbers(argument: _pb_NumberRequest, metadata: grpc.Metadata, options?: grpc.CallOptions): grpc.ClientReadableStream<_pb_NumberResponse__Output>;
  randomNumbers(argument: _pb_NumberRequest, options?: grpc.CallOptions): grpc.ClientReadableStream<_pb_NumberResponse__Output>;
  
  TodoList(metadata: grpc.Metadata, options: grpc.CallOptions, callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  TodoList(metadata: grpc.Metadata, callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  TodoList(options: grpc.CallOptions, callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  TodoList(callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  todoList(metadata: grpc.Metadata, options: grpc.CallOptions, callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  todoList(metadata: grpc.Metadata, callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  todoList(options: grpc.CallOptions, callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  todoList(callback: grpc.requestCallback<_pb_TodoResponse__Output>): grpc.ClientWritableStream<_pb_TodoRequest>;
  
}

export interface RandomHandlers extends grpc.UntypedServiceImplementation {
  Chat: grpc.handleBidiStreamingCall<_pb_ChatRequest__Output, _pb_ChatResponse>;
  
  PingPong: grpc.handleUnaryCall<_pb_PingRequest__Output, _pb_PongResponse>;
  
  RandomNumbers: grpc.handleServerStreamingCall<_pb_NumberRequest__Output, _pb_NumberResponse>;
  
  TodoList: grpc.handleClientStreamingCall<_pb_TodoRequest__Output, _pb_TodoResponse>;
  
}

export interface RandomDefinition extends grpc.ServiceDefinition {
  Chat: MethodDefinition<_pb_ChatRequest, _pb_ChatResponse, _pb_ChatRequest__Output, _pb_ChatResponse__Output>
  PingPong: MethodDefinition<_pb_PingRequest, _pb_PongResponse, _pb_PingRequest__Output, _pb_PongResponse__Output>
  RandomNumbers: MethodDefinition<_pb_NumberRequest, _pb_NumberResponse, _pb_NumberRequest__Output, _pb_NumberResponse__Output>
  TodoList: MethodDefinition<_pb_TodoRequest, _pb_TodoResponse, _pb_TodoRequest__Output, _pb_TodoResponse__Output>
}
