#include "tests.h"

START_TEST(strcmp_1) {
  char s1[] = "gosha";
  char s2[] = "gosha";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_2) {
  char s1[] = "gosha";
  char s2[] = "ilya";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_3) {
  char s1[] = "";
  char s2[] = "";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_4) {
  char s1[] = "u";
  char s2[] = "\0";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_5) {
  char s1[] = "\0";
  char s2[] = "j";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_6) {
  char s1[] = "\0";
  char s2[] = "\0";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_7) {
  char s1[] = "123 ilya \0 45678 gosh";
  char s2[] = "ilya";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *suite_strcmp() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_strcmp" RESET);
  TCase *tc = tcase_create("strcsuite_strcmp_tc");

  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strcmp_4);
  tcase_add_test(tc, strcmp_5);
  tcase_add_test(tc, strcmp_6);
  tcase_add_test(tc, strcmp_7);

  suite_add_tcase(s, tc);
  return s;
}
