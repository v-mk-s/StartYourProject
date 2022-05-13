HOST = 0.0.0.0
PORT = 8000
THREADS = 1

TEST_FILTER = *

.PHONY: all build rebuild clean build_tests build_server_tests build_client_tests run_server_tests

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
	
build_server_tests:
	./build.sh -DWITH_SERVER_TESTS=ON

build_client_tests:
	./build.sh -DWITH_CLIENT_TESTS=ON

build_tests: build_server_tests build_client_tests

run_server_tests:
	./build/tests/test_server/test_server_syp --gtest_filter=${TEST_FILTER}
