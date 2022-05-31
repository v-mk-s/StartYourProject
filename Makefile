HOST = 0.0.0.0
PORT = 8080
THREADS = 1

TEST_FILTER = *

.PHONY: all build rebuild clean build_tests build_server_tests build_client_tests run_server_tests

all: build

clean:
	rm -rf build

build_server:
	./build.sh -DSERVER=ON -DCLIENT=OFF

build_client:
	./build.sh -DSERVER=OFF -DCLIENT=ON

build:
	./build.sh -DSERVER=ON -DCLIENT=ON

rebuild: clean build

build_server_tests:
	./build.sh -DWITH_SERVER_TESTS=ON -DWITH_CLIENT_TESTS=OFF

build_client_tests:
	./build.sh -DWITH_SERVER_TESTS=OFF -DWITH_CLIENT_TESTS=ON

build_tests:
	./build.sh -DWITH_SERVER_TESTS=ON -DWITH_CLIENT_TESTS=ON

run_server_tests:
	./build/tests/test_server/test_server_syp --gtest_filter=${TEST_FILTER}

run_server:
	./build/server/network/server_syp_network $(HOST) $(PORT) . $(THREADS)

run_client:
	./build/client/client $(HOST) $(PORT)
	
run_client_tests:
	./build/tests/test_client/test_client_syp --gtest_filter=${TEST_FILTER}
