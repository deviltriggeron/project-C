(CC) = gcc -Wall -Werror -Wextra

cat: cat.o
	$(CC) $^ -o cat

cat.o: cat.c cat.h
	$(CC) -c $< -o $@

clang-check:
	clang-format -n *.c *.h

clang-repair:
	clang-format -i *.c *.h

clean:
	rm -rf *.o cat *.out

rebuild:
	rm -rf *.o | make
