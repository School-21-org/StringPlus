CC = gcc
CFLAGS = -Wall -Wextra -Werror -g --std=c11
OBJ_DIR = objects/
SOURCE = $(wildcard *.c) # get list all *.c
OBJECT = $(patsubst %.c, %.o, $(SOURCE))  # replace .c -> .o (making object files)
SOURCE_TEST = $(wildcard tests/*.c)
SOURCE_LIBRARY = $(SOURCE)
OBJECT_LIBRARY = $(patsubst %.c, %.o, $(SOURCE_LIBRARY))
EXECUTABLE = s21_test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -DLinux
	GFLAGS = -lcheck_pic -lm -lsubunit
	RM_COMMAND = rm -rf test*.gcda test*.gcno
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -DDarwin
	GFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcheck -lm
	RM_COMMAND = rm test*.gcda test*.gcno
endif

.PHONY: all s21_string.a test gcov_report style clang clean rebuild valgrind_test cppcheck_test

all: clean s21_string.a test gcov_report

s21_string.a: clean $(OBJECT_LIBRARY)
	@ar rc s21_string.a $(OBJECT_LIBRARY)
	@ranlib s21_string.a
	@rm -rf *.o

test: clean s21_string.a
	@$(CC) $(CFLAGS) $(SOURCE_TEST) s21_string.a -o $(EXECUTABLE) $(GFLAGS)
	@./$(EXECUTABLE)

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) $(SOURCE_TEST) -o $(EXECUTABLE) $(GFLAGS) --coverage 
	@./$(EXECUTABLE)
	@lcov -t "s21_tests" -o s21_tests.info -c -d . --exclude "tests/*"
	@genhtml -o report s21_tests.info
	@rm -rf *.gcno *.gcda *.gcov

style: clean
	@cp ../materials/linters/.clang-format ./
	@clang-format -n *.c
	@clang-format -n *.h
	@rm -rf .clang-format

clang: clean
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c
	@clang-format -i *.h
	@rm -rf .clang-format

clean:
	@rm -f *.o *.a *.gcno *.gcda *.info $(EXECUTABLE) valgrind_out.txt
	@rm -rf report $(OBJ_DIR)

rebuild: clean s21_string.a test

valgrind_test: rebuild
	valgrind -s -q --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind_out.txt ./$(EXECUTABLE)

cppcheck_test: rebuild
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCE)
