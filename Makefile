CC=gcc
CFLAGS =-Wall -Wextra -std=c99 -pedantic -ggdb -Ivendor/include -Isrc

SRC=src/utf8.c
TEST_SRC=test/test_utf8.c vendor/unity.c
BIN_DIR=bin
TEST_BIN=$(BIN_DIR)/test

test: setup
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o bin/test
	./$(TEST_BIN)

setup:
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

.PHONY: test
