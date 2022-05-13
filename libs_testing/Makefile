HOST = 0.0.0.0
PORT = 8000
THREADS = 1

.PHONY: all build run_server run_client clean

all: build

build:
	# g++ server.cpp -ggdb3 -o server.out -lpthread
	g++ client.cpp -ggdb3 -o client.out -lpthread

run_server:
	./server.out $(HOST) $(PORT) . THREADS

run_client:
	./client.out $(HOST) $(PORT)

clean:
	rm -rf *.out