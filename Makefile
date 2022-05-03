.PHONY: all build rebuild clean build_tests build_server_tests build_client_tests

all: clean build

clean:
	rm -rf build

build:
	./build.sh

rebuild: clean build

build_server_tests:
	./build.sh -DWITH_SERVER_TESTS=ON

build_client_tests:
	./build.sh -DWITH_CLIENT_TESTS=ON

build_tests: build_server_tests build_client_tests