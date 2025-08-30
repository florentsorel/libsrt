#include "lexer.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_init_with_null(void) {
  lexer_t lexer;
  int rc = srt_lexer_init(&lexer, NULL);
  TEST_ASSERT_EQUAL_INT(-1, rc);
}

void test_init_with_valid_input(void) {
  lexer_t lexer;
  int rc = srt_lexer_init(&lexer, "Hello\n");
  TEST_ASSERT_EQUAL_INT(0, rc);
  TEST_ASSERT_NOT_NULL(lexer.input);
  srt_lexer_free(&lexer);
}

void test_read_char(void) {
  lexer_t lexer;
  srt_lexer_init(&lexer, "Aé\n");

  TEST_ASSERT_EQUAL_CHAR('A', lexer.ch);

  read_char(&lexer);
  TEST_ASSERT_EQUAL_CHAR((unsigned char)0xC3, lexer.ch);  // First byte of 'é'

  read_char(&lexer);
  TEST_ASSERT_EQUAL_CHAR('\n', lexer.ch);

  read_char(&lexer);
  TEST_ASSERT_EQUAL_CHAR('\0', lexer.ch);

  srt_lexer_free(&lexer);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_init_with_null);
  RUN_TEST(test_init_with_valid_input);
  RUN_TEST(test_read_char);
  return UNITY_END();
}
