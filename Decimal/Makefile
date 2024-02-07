gcc = gcc -g -Wall -Werror -Wextra
HEAD = decimal.h
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


all: test decimal.a gcov_report

decimal.a: funcForA
	ar rcs $@ $(oF)
	ranlib decimal.a

funcForA: library
	$(gcc) -c $(fF)

test: functions 
	$(gcc) $(objectFiles) $(oF) -o decimal $(CHECK_FLAGS)
	./decimal

library:
	$(gcc) $(HEAD)

functions: library
	$(gcc) -c $(functionFiles) $(fF)

gcov_report: functions 
	gcc --coverage $(functionFiles) $(fF) -o test $(CHECK_FLAGS) 
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

clean:
	rm -rf *.o *.gch *.gcno *.gcda *.test test.info decimal ./report/* ./TEST/*.gch test decimal.a

rebuild:
	rm -rf *.o *.gch *.gcno *.gcda *.test test.info decimal ./report/* ./TEST/*.gch test decimal.a | make
