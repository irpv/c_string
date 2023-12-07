#include "tests.h"

START_TEST(strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] =
      "217867832645879623475632479856978324697856923471298390123123324423523 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[] = "why i have to do this((((";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  char str[] = "          00000000           ......  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  char str[] = "\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_10) {
  char str[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_12) {
  char str[] = "\t\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_13) {
  char str[] = "\0test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_14) {
  char str[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *suite_strlen() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_strlen" RESET);
  TCase *tc = tcase_create("strcsuite_strlen_tc");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_7);
  tcase_add_test(tc, strlen_8);
  tcase_add_test(tc, strlen_9);
  tcase_add_test(tc, strlen_10);
  tcase_add_test(tc, strlen_11);
  tcase_add_test(tc, strlen_12);
  tcase_add_test(tc, strlen_13);
  tcase_add_test(tc, strlen_14);

  suite_add_tcase(s, tc);
  return s;
}
