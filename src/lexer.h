#ifndef LIBSRT_LEXER_H
#define LIBSRT_LEXER_H

#include <stddef.h>

typedef struct {
    char *input;
    size_t length;
    size_t position;
    size_t next_position;
    char ch;
    size_t line;
    size_t column;
} lexer_t;

int srt_lexer_init(lexer_t *lexer, const char *input);
void srt_lexer_free(lexer_t *lexer);
void read_char(lexer_t *lexer);

#endif // LIBSRT_LEXER_H
