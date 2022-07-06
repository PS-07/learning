import type * as grpc from '@grpc/grpc-js';
import type { MessageTypeDefinition } from '@grpc/proto-loader';

import type { RandomClient as _pb_RandomClient, RandomDefinition as _pb_RandomDefinition } from './pb/Random';

type SubtypeConstructor<Constructor extends new (...args: any) => any, Subtype> = {
  new(...args: ConstructorParameters<Constructor>): Subtype;
};

export interface ProtoGrpcType {
  pb: {
    ChatRequest: MessageTypeDefinition
    ChatResponse: MessageTypeDefinition
    NumberRequest: MessageTypeDefinition
    NumberResponse: MessageTypeDefinition
    PingRequest: MessageTypeDefinition
    PongResponse: MessageTypeDefinition
    Random: SubtypeConstructor<typeof grpc.Client, _pb_RandomClient> & { service: _pb_RandomDefinition }
    TodoRequest: MessageTypeDefinition
    TodoResponse: MessageTypeDefinition
  }
}

