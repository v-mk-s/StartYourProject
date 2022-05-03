HOST = 0.0.0.0
PORT = 8000
THREADS = 1

.PHONY: all build rebuild clean build_server_example run_server_example

all: clean build

clean:
	rm -rf build

build:
	./build.sh

rebuild: clean build

build_server_example: clean
	./build.sh -DSERVER_EXAMPLE=ON

run_server_example:
	./build/libs_testing/boost_testing $(HOST) $(PORT) . THREADS