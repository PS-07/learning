init:
	yarn init -y
	yarn add --dev @grpc/grpc-js @grpc/proto-loader typescript ts-node

gen:
	yarn proto-loader-gen-types --grpcLib=@grpc/grpc-js --outDir=proto/ proto/*.proto

server:
	yarn server

user1:
	yarn client user1

user2:
	yarn client user2