.PHONY: all build rebuild clean

all: clean build

clean:
	rm -rf build

build:
	./build.sh

rebuild: clean build