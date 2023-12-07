#include "tests.h"

START_TEST(strerror_1) {
  for (int i = -1000; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

Suite *suite_strerror() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_strerror" RESET);
  TCase *tc = tcase_create("strcsuite_strerror_tc");

  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);

  suite_add_tcase(s, tc);
  return s;
}
