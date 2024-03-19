.PHONY: all s21_math.a

CC=gcc
FLAGS=-std=c11 -g -Wall -Werror -Wextra
TEST_FLAGS=-lm
S21_MATH_C=s21_*.c
S21_MATH_H=s21_*.h
S21_MATH_O=s21_*.o
TESTS=tests

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS+=-lsubunit -lgcov
endif

all: s21_math.a

s21_math.a:
	$(CC) $(S21_MATH_C) -c $(FLAGS)
	ar rc s21_math.a $(S21_MATH_O)
	ranlib s21_math.a

s21_covered:
	$(CC) $(S21_MATH_C) -c $(FLAGS) --coverage
	ar rc s21_math.a $(S21_MATH_O)
	ranlib s21_math.a

style:
	clang-format -style=google -i $(TESTS).c $(S21_MATH_C) $(S21_MATH_H)
	python3 ./cpplint.py --extension=c $(TESTS).c $(S21_MATH_C) $(S21_MATH_H)
	cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem $(TESTS).c $(S21_MATH_C) $(S21_MATH_H)

commit:
	git add Makefile $(TESTS).c $(S21_MATH_C) $(S21_MATH_H) 

test: clean s21_covered
	$(CC) -o $(TESTS).o $(TESTS).c -c $(FLAGS) --coverage
	$(CC) $(TESTS).o s21_math.a -o $(TESTS) -lcheck --coverage $(FLAGS) $(TEST_FLAGS)
	./$(TESTS)

mem: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TESTS)
else
	leaks --atExit -- ./$(TESTS)
endif

clean:
	rm -rf $(S21_MATH_O) s21_math.a $(TESTS).o $(TESTS) *.gcda *.gcno *.gcov *.info *.html report

rebuild: clean all

gcov_report: test
	lcov -t "s21_math" -o s21_math.info -c -d .
	genhtml -o report s21_math.info
