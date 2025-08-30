#include "utf8.h"
#include <stdio.h>

int utf8_byte_length(unsigned char first_byte) {
  if ((first_byte & 0x80) == 0x00)  // 0xxxxxxx
    return 1;
  else if ((first_byte & 0xE0) == 0xC0)  // 110xxxxx
    return 2;
  else if ((first_byte & 0xF0) == 0xE0)  // 1110xxxx
    return 3;
  else if ((first_byte & 0xF8) == 0xF0)  // 11110xxx
    return 4;
  else
    return -1;
}
