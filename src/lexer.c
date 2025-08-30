#include "lexer.h"
#include <stdlib.h>
#include <string.h>
#include "utf8.h"

int srt_lexer_init(lexer_t* lexer, const char* input) {
  if (lexer == NULL || input == NULL) {
    return -1;
  }

  size_t len = strlen(input);
  lexer->input = malloc(len + 1);
  if (lexer->input == NULL) {
    lexer->length = 0;
    return -2;
  }
  strcpy(lexer->input, input);
  lexer->length = len;
  lexer->position = 0;
  lexer->next_position = 0;
  lexer->ch = '\0';
  lexer->line = 0;
  lexer->column = 0;

  read_char(lexer);

  return 0;
}

void srt_lexer_free(lexer_t* lexer) {
  if (lexer == NULL) {
    return;
  }

  free(lexer->input);
  lexer->input = NULL;
  lexer->length = 0;
  lexer->position = 0;
  lexer->next_position = 0;
  lexer->ch = '\0';
  lexer->line = 0;
  lexer->column = 0;
}

void read_char(lexer_t* lexer) {
  if (lexer == NULL || lexer->input == NULL ||
      lexer->next_position >= lexer->length) {
    lexer->ch = '\0';
    return;
  }

  unsigned char first_byte = (unsigned char)lexer->input[lexer->next_position];
  int char_size = utf8_byte_length(first_byte);

  if (char_size < 0 || lexer->next_position + char_size > lexer->length) {
    // invalid UTF-8 sequence → treat as end of input
    lexer->ch = '\0';
    return;
  }

  // store current character (first byte only, for now)
  lexer->ch = first_byte;

  lexer->position = lexer->next_position;
  lexer->next_position += char_size;

  // update line/column
  if (first_byte == '\n') {
    lexer->line++;
    lexer->column = 0;
  } else {
    lexer->column++;
  }
}
