CC=gcc
CFLAGS =-Wall -Wextra -std=c99 -pedantic -ggdb -Ivendor/include -Isrc

SRC=src/utf8.c src/lexer.c
TEST_LEXER_SRC=src/lexer.c src/utf8.c test/test_lexer.c
TEST_UTF8_SRC=src/utf8.c test/test_utf8.c
VENDOR_SRC=vendor/unity.c
BIN_DIR=bin
TEST_BIN=$(BIN_DIR)/test

test: setup
	$(CC) $(CFLAGS) $(TEST_UTF8_SRC) $(VENDOR_SRC) -o bin/test_utf8
	./bin/test_utf8
	$(CC) $(CFLAGS) $(TEST_LEXER_SRC) $(VENDOR_SRC) -o bin/test_lexer
	./bin/test_lexer

setup:
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

.PHONY: test
