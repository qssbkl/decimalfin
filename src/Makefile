CC=gcc -std=c11
CC1=clang
#CFLAGS_FOR_FUNC=
CFLAGS_FOR_FUNC=-Wall -Wextra -Werror 
CFLAGS=
#ADD_CFLAGS=-g
ADD_CFLAGS=-g -Wno-unused-parameter
LIBS=-lcheck
SOURCES= s21_add.c s21_div.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c \
s21_from_float_to_decimal.c s21_from_int_to_decimal.c s21_is_equal.c s21_is_greater_or_equal.c \
s21_is_greater.c s21_is_less_or_equal.c s21_is_less.c s21_is_not_equal.c s21_mod.c s21_mul.c \
s21_sub.c s21_decimal_common_functions.c \
s21_truncate.c s21_round.c s21_negate.c s21_floor.c
OBJECTS=$(SOURCES:.c=.o)
BREW_HOME = $(shell brew config | grep HOMEBREW_PREFIX | cut -d" " -f2)
#PATH-TO-CHECK=-I${BREW_HOME}/include
#PATH-TO-LIB-CHECK=-L${BREW_HOME}/Cellar/check/0.15.2/lib
PATH-TO-CHECK=
PATH-TO-LIB-CHECK=


GCOV_TEST = gcov_test
GCOV_DIR = report

EXECUTABLE=s21_decimal_test_manual


all: s21_decimal.a test gcov_report clean


doit_for_decimal:$(SOURCES) s21_decimal.h
	$(foreach var,$(SOURCES), $(CC) $(CFLAGS_FOR_FUNC) -c $(var);)

s21_decimal.a: doit_for_decimal
	ar rcs s21_decimal.a $(OBJECTS)
	cp s21_decimal.a libs21_decimal.a
	rm lib*.a *.o

test: s21_decimal_test
	rm *.o
	./s21_decimal_test

s21_decimal_test: s21_decimal.a s21_decimal_test.o
	$(CC) -o s21_decimal_test  s21_decimal_test.o s21_decimal.a $(PATH-TO-CHECK) $(PATH-TO-LIB-CHECK) -lcheck

s21_decimal_test.o: s21_decimal_test.c s21_decimal.h
	$(CC) $(CFLAGS) -c s21_decimal_test.c -lcheck -lm $(PATH-TO-CHECK)

gcov_report: 
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(ADD_CFLAGS) --coverage s21_decimal_test.c $(SOURCES) -o s21_decimal_test `pkg-config --cflags --libs check`
	./s21_decimal_test
	lcov -t "s21_decimal_test" -o s21_decimal_test.info -c -d .   
	genhtml -o report s21_decimal_test.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_decimal_test s21_decimal_test.info
else
	$(CC) $(CFLAGS) $(ADD_CFLAGS) --coverage s21_decimal_test.c $(SOURCES) -o s21_decimal_test $(PATH-TO-CHECK) $(PATH-TO-LIB-CHECK) -lcheck
	./s21_decimal_test
	lcov -t "s21_decimal_test" -o s21_decimal_test.info -c -d .  
	genhtml -o report s21_decimal_test.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_decimal_test s21_decimal_test.info
endif

clean_all: clean clean_gcov

clean:
	rm *.o *.a

clean_gcov:
	rm -rf ./*.gcda ./*.gcno ./*.info ./$(GCOV_TEST) ./$(GCOV_DIR)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.h *.c
	python3 ../materials/linters/cpplint.py --extensions=c ./*.c *.h

mem_check:
ifeq ($(OS), Darwin)
	valgrind --tool=memcheck ./s21_decimal_test
else
	CK_FORK=no leaks -atExit -- ./s21_decimal_test
endif
