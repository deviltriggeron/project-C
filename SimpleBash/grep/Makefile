(CC) = gcc -g -Wall -Werror -Wextra

all: grep test

grep: grep.o
	$(CC) $^ -o grep

grep.o: grep.c grep.h
	$(CC) -c $< -o $@

test:
	bash test.sh

clang-check:
	clang-format -n *.c *.h

clang-repair:
	clang-format -i *.c *.h

clean:
	rm -rf *.o grep *.out

rebuild:
	rm -rf *.o | make