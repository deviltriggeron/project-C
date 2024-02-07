gcc = gcc -c -Wall -Werror -Wextra -std=c11
MODULES = $(wildcard help/*.c)
OBJECTS = $(patsubst %.c, %.o, $(MODULES))

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck -lm
endif

all: clean install 

%.o: %.c
	mkdir -p obj
	$(gcc) $< $(CHECK_FLAGS) -o $(patsubst help%, obj%, $@)

smart_calc.o: smart_calc.c 
	$(gcc) smart_calc.c $(CHECK_FLAGS) -o smart_calc.o

install:
	mkdir -p ../build
	cd SmartCalc && qmake && make && make clean && rm -rf Makefile && mv SmartCalc.app ../../build/SmartCalc.app

uninstall:
	rm -rf ../build

dvi_install:
	brew install doxygen

dvi:
	rm -rf Doxyfiles
	doxygen doxy
	open Doxyfiles/html/index.html

dist:
	rm -rf SmartCalculator
	mkdir SmartCalculator
	mkdir SmartCalculator/src
	cp Makefile *.c *.h SmartCalc/*.cpp SmartCalc/*.ui SmartCalc/*.pro SmartCalc/*.pro.user help/header/*.h help/*.c SmartCalculator/src/
	tar -cvzf SmartCalculator.tar.gz SmartCalculator
	rm -rf SmartCalculator/

gcov_report: smart_calc.o $(OBJECTS)
	gcc --coverage -Wall -Werror -Wextra -std=c11 ./TEST/help_test.c $(CHECK_FLAGS) ./help/*.c -o ./TEST/test_help
	./TEST/test_help
	mkdir -p TEST/modules_gcov
	mv *.gcno ./TEST/modules_gcov/ && mv *.gcda ./TEST/modules_gcov/
	lcov -t "test_coverage" -o test_coverage.info -c -d .
	gcc --coverage -Wall -Werror -Wextra -std=c11 ./TEST/smart_calc_test.c $(CHECK_FLAGS) ./help/*.c smart_calc.c -o ./TEST/test_calc
	./TEST/test_calc
	mkdir -p TEST/controller_gcov
	mv *.gcno ./TEST/controller_gcov/ && mv *.gcda ./TEST/controller_gcov/
	lcov -t "test_coverage" -o test_coverage.info -c -d .
	genhtml -o report test_coverage.info
	open report/index.html
	rm -rf *.gcda *.gcno report/test_coverage.info TEST/modules_gcov TEST/controller_gcov

clean:
	@rm -rf TEST/logs/*.log TEST/test_help TEST/test_calc obj *.dSYM **/*.dSYM report test_coverage.info *.gcda *.gcno report/test_coverage.info TEST/modules_gcov TEST/controller_gcov smart_calc.o Doxyfiles
