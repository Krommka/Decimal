CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -g -O0 
GCOVFLAGS = -fprofile-arcs -ftest-coverage
DEBUG = -DDEBUG
LDFLAGS = -lgcov

DECIMAL_DIR = s21_decimal
TEST_DIR = tests

BINARY = binary
BINARY_ARITHMETIC = $(BINARY)/binary_arithmetic
ARITHMETIC = arithmetic
ARITHMETIC_SERVICE = $(ARITHMETIC)/service
CONVERSION = conversion
COMPARISON = comparison
OTHER = other

COMMON_DIR = $(ARITHMETIC) $(COMPARISON) $(CONVERSION) $(OTHER)

SRC_DIRS = $(addprefix $(DECIMAL_DIR)/, $(COMMON_DIR) $(BINARY) $(BINARY_ARITHMETIC) $(ARITHMETIC_SERVICE))
TEST_DIRS = $(addprefix $(TEST_DIR)/, $(COMMON_DIR)) $(TEST_DIR)

SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
TEST_SRCS = $(wildcard $(addsuffix /*.c, $(TEST_DIRS)))

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.o=.c)

OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS = -lcheck -lm -lsubunit 
else
	CHECKFLAGS = -lcheck 
endif

all : s21_decimal.a test gcov_report

s21_decimal.a: $(OBJS) 
	@ar rcs $@ $^

debug: CFLAGS += $(DEBUG)
debug: test

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test : $(TEST_DIR)/s21_decimal_test.c $(TEST_OBJS) $(OBJS)
	$(CC) $^ $(CHECKFLAGS) $(CFLAGS) -o $@

gcov_report:
	$(CC) $(SRCS) $(TEST_SRCS) $(CHECKFLAGS) $(CFLAGS) $(GCOVFLAGS) $(LDFLAGS) -o report.out
	./report.out
	find ./ -type f -iname '*.gcda'
	lcov -o report.info -c -d .
	rm -rf ./cov-report
	mkdir ./cov-report
	genhtml -o ./cov-report/ report.info
	rm *.gcno *.gcda report.out report.info

.PHONY: s21_decimal.a test debug clean *.o 

SRC_CLEAN = $(addsuffix /*.o, $(SRC_DIRS))
TEST_CLEAN = $(addsuffix /*.o, $(TEST_DIRS)) $(TEST_DIR)/*.o

clean:
	rm -f $(SRC_CLEAN) $(TEST_CLEAN) rm *.gcno *.gcda \
	report.out report.info test s21_decimal.a
