CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

all: s21_string.a test

clean:
		rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov *.a
		rm -rf report/

test:
		${CC} ${FLAGS} s21_*.c main.c tests/test_*.c -g `pkg-config --cflags --libs check`

s21_string.o: s21_string.h s21_cs.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_sprintf.c s21_strcat.c s21_strchr.c s21_strcmp.c s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c s21_strpbrk.c s21_strrchr.c s21_strspn.c s21_strstr.c s21_strtok.c
		${CC} ${FLAGS} -O -c s21_cs.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_sprintf.c s21_strcat.c s21_strchr.c s21_strcmp.c s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c s21_strpbrk.c s21_strrchr.c s21_strspn.c s21_strstr.c s21_strtok.c

s21_string.a: s21_string.o
		ar rc s21_string.a s21_cs.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memmove.o s21_memset.o s21_sprintf.o s21_strcat.o s21_strchr.o s21_strcmp.o s21_strcpy.o s21_strcspn.o s21_strerror.o s21_strlen.o s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o s21_strspn.o s21_strstr.o s21_strtok.o
		ranlib s21_string.a

gcov_report:
		${CC} -fprofile-arcs -ftest-coverage ${FLAGS} s21_*.c main.c tests/test_*.c -g `pkg-config --cflags --libs check`
		./a.out
		lcov -t "coverage_report" -o coverage.info -c -d .
		genhtml -o report coverage.info

tst: s21_string.a
		${CC} ${FLAGS} -lm main.c tests/test_*.c s21_string.a -g `pkg-config --cflags --libs check`
