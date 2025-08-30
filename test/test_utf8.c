#include "unity.h"
#include "utf8.h"

void setUp(void) {}

void tearDown(void) {}

void test_utf8_byte_length_returns_1(void) {
  int sut = utf8_byte_length(0x41);  // A
  TEST_ASSERT_EQUAL_INT(1, sut);
}

void test_utf8_byte_length_returns_2(void) {
  int sut = utf8_byte_length(0xC3);  // é
  TEST_ASSERT_EQUAL_INT(2, sut);
}

void test_utf8_byte_length_returns_3(void) {
  int sut = utf8_byte_length(0xE6);  // 漢
  TEST_ASSERT_EQUAL_INT(3, sut);
}

void test_utf8_byte_length_returns_4(void) {
  int sut = utf8_byte_length(0xF0);  // 😀
  TEST_ASSERT_EQUAL_INT(4, sut);
}

void test_utf8_byte_length_returns_minus1(void) {
  int sut = utf8_byte_length(0xFF);  // invalid first byte
  TEST_ASSERT_EQUAL_INT(-1, sut);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_utf8_byte_length_returns_1);
  RUN_TEST(test_utf8_byte_length_returns_2);
  RUN_TEST(test_utf8_byte_length_returns_3);
  RUN_TEST(test_utf8_byte_length_returns_4);
  RUN_TEST(test_utf8_byte_length_returns_minus1);
  return UNITY_END();
}
