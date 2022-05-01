.PHONY: all build run_server run_client clean

all: build

build:
	g++ server.cpp -o server.out -lpthread
	g++ client.cpp -o client.out -lpthread

run_server:
	./server.out 0.0.0.0 8080 . 1

run_client:
	./client.out 0.0.0.0 8080

clean:
	rm -rf *.out