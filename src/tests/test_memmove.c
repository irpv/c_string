#include "tests.h"

START_TEST(memmove_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "forward";
  s21_size_t n = 0;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_4) {
  char s1[] = "total: 244  failed: 0  success: 244";
  char s2[] = "total: 244  failed: 0  success: 244";
  s21_size_t n = 6;
  memmove(s1, s1, n);
  s21_memmove(s2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_5) {
  char s1[] = "H";
  char s2[] = "H";
  char s3[] = "Hi";
  s21_size_t n = 2;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_6) {
  char s1[] = "jijijij";
  char s2[] = "jijijij";
  char s3[] = "\0";
  s21_size_t n = 1;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_7) {
  char s1[] = "           ";
  char s2[] = "           ";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_8) {
  char s1[] = "765\078423";
  char s2[] = "765\078423";
  char s3[] = "com";
  s21_size_t n = 3;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_9) {
  char s1[] = "76578423";
  char s2[] = "76578423";
  char s3[] = "c";
  s21_size_t n = 1;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_10) {
  char s1[] = "76578423";
  char s2[] = "76578423";
  char s3[] = "com";
  s21_size_t n = 4;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

Suite *suite_memmove() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_memmove" RESET);
  TCase *tc = tcase_create("memmove_tc");

  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memmove_5);
  tcase_add_test(tc, memmove_6);
  tcase_add_test(tc, memmove_7);
  tcase_add_test(tc, memmove_8);
  tcase_add_test(tc, memmove_9);
  tcase_add_test(tc, memmove_10);

  suite_add_tcase(s, tc);
  return s;
}
