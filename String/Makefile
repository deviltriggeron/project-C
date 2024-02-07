gcc = gcc -g -Wall -Werror -Wextra
HEAD = sstring.h
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


all: test string.a gcov_report

string.a: funcForA
	ar rcs $@ $(oF)
	ranlib string.a

funcForA: library
	$(gcc) -c $(fF)

library:
	$(gcc) $(HEAD)

functions: library
	$(gcc) -c $(functionFiles) $(fF)

clean:
	rm -rf *.o test string.a

rebuild:
	rm -rf *.o test string.a | make
