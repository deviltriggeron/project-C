gcc = gcc -g -Wall -Werror -Wextra
HEAD = matrix.h
objectFiles = $(shell find . -name "test*.o")
functionFiles = $(shell find . -name "test*.c")
oF = $(shell find . -name "s21*.o")
fF = $(shell find . -name "s21*.c")
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif


all: test matrix.a gcov_report

matrix.a: funcForA
	ar rcs $@ $(oF)
	ranlib matrix.a

funcForA: library
	$(gcc) -c $(fF)

test: functions 
	$(gcc) $(objectFiles) $(oF) -o matrix $(CHECK_FLAGS)
	./matrix

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
	rm -rf *.o *.gch *.gcno *.gcda *.test test.info matrix ./report/* ./TEST/*.gch test matrix.a

rebuild:
	rm -rf *.o *.gch *.gcno *.gcda *.test test.info matrix ./report/* ./TEST/*.gch test matrix.a | make
