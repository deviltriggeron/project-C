gcc = gcc -g -Wall -Werror -Wextra
HEAD = smath.h
objectFiles = $(shell find . -name "test*.o")
functionFiles = $(shell find . -name "test*.c")
oF = $(shell find . -name "*.o")
fF = $(shell find . -name "*.c")
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif


all: smath.a

smath.a: funcForA
	ar rcs $@ $(oF)
	ranlib smath.a

funcForA: library
	$(gcc) -c $(fF)

library:
	$(gcc) $(HEAD)

functions: library
	$(gcc) -c $(functionFiles) $(fF)

clean:
	rm -rf *.o smath  test smath.a

rebuild:
	rm -rf *.o smath  test smath.a | make
