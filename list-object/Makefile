all: build run
test: test-compile run test-results

build:
	gcc -o ./build/app ./src/main.c ./src/list.c

run:
	./build/app

clean:
	rm ./build/app

# test-compile:
# 	gcc -o ./build/app -fprofile-arcs -ftest-coverage ./src/main.c ./src/list.c

# test-results:
# 	gcov -o ./build/app ./src/main.c

transpile:
	python3 transpiler.py && mv x.c ./src/x.c && gcc -o ./build/x ./src/x.c ./src/list.c && rm ./src/x.c && ./build/x
