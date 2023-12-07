#include "tests.h"

#define BUFFER 500
#define TEST_SIZE 5

void start_check_int(char (*format)[50], int *value) {
  char str1[BUFFER];
  char str2[BUFFER];
  int a, b;

  for (int i = 0; i < TEST_SIZE; i++) {
    for (int j = 0; j < TEST_SIZE; j++) {
      a = s21_sprintf(str1, format[i], value[j]);
      b = sprintf(str2, format[i], value[j]);
      ck_assert_msg((a == b) && !strcmp(str1, str2),
                    "format == \"%s\", value == %d, a == %d, b == %d, str1 == "
                    "\"%s\", str2 == \"%s\"",
                    format[i], value[j], a, b, str1, str2);
    }
  }
}

void start_check_double(char (*format)[50], double *value) {
  char str1[BUFFER];
  char str2[BUFFER];
  int a, b;

  for (int i = 0; i < TEST_SIZE; i++) {
    for (int j = 0; j < TEST_SIZE; j++) {
      a = s21_sprintf(str1, format[i], value[j]);
      b = sprintf(str2, format[i], value[j]);
      ck_assert_msg((a == b) && !strcmp(str1, str2),
                    "format == \"%s\", value == %f, a == %d, b == %d, str1 == "
                    "\"%s\", str2 == \"%s\"",
                    format[i], value[j], a, b, str1, str2);
    }
  }
}

START_TEST(sprintf_1) {
  char format[TEST_SIZE][50] = {"%c", "%+-07.7c", "%+c", "%.7c", "%15c"};
  char value[TEST_SIZE] = {'t', '\r', '\\', '8', ' '};

  char str1[BUFFER];
  char str2[BUFFER];
  int a, b;

  for (int i = 0; i < TEST_SIZE; i++) {
    for (int j = 0; j < TEST_SIZE; j++) {
      a = s21_sprintf(str1, format[i], value[j]);
      b = sprintf(str2, format[i], value[j]);
      ck_assert_msg((a == b) && !strcmp(str1, str2),
                    "format == \"%s\", value == %c, a == %d, b == %d, str1 == "
                    "\"%s\", str2 == \"%s\"",
                    format[i], value[j], a, b, str1, str2);
    }
  }
}
END_TEST

START_TEST(sprintf_2) {
  char format[TEST_SIZE][50] = {"%.15s", "%+-07.7s", "%+s", "%.7s", "%15s"};
  char *v1 = "text";
  char *v2 = "text\n";
  char *v3 = "\0";
  char *v4 = "\"\r\\r\n\0";
  char *v5 = "1234569898";
  char *value[] = {v1, v2, v3, v4, v5};

  char str1[BUFFER];
  char str2[BUFFER];
  int a, b;

  for (int i = 0; i < TEST_SIZE; i++) {
    for (int j = 0; j < TEST_SIZE; j++) {
      a = s21_sprintf(str1, format[i], value[j]);
      b = sprintf(str2, format[i], value[j]);
      ck_assert_msg((a == b) && !strcmp(str1, str2),
                    "format == \"%s\", value == %s, a == %d, b == %d, str1 == "
                    "\"%s\", str2 == \"%s\"",
                    format[i], value[j], a, b, str1, str2);
    }
  }
}
END_TEST

START_TEST(sprintf_3) {
  char format[TEST_SIZE][50] = {
      "%d", "%.7d", "%15d", "%i", "%+i",
  };
  int value[TEST_SIZE] = {-123456789, 1, INT32_MAX, 0, -10};
  start_check_int(format, value);
}
END_TEST

START_TEST(sprintf_4) {
  char format[TEST_SIZE][50] = {"%u", "%+-07.7u", "%+u", "%.7u", "%15u"};
  int value[TEST_SIZE] = {-123456789, 1, INT32_MAX, 0, -10};
  start_check_int(format, value);
}
END_TEST

START_TEST(sprintf_5) {
  char format[TEST_SIZE][50] = {"%f", "%+-10.7f", "%+f", "%.7f", "%15f"};
  double value[TEST_SIZE] = {123.123, 0.00, -1234565545.999999999999, 0, -1};
  start_check_double(format, value);
}
END_TEST

START_TEST(sprintf_6) {
  char str1[BUFFER];
  char str2[BUFFER];
  char *format = "123456789%n";
  int n1, n2;
  int a, b;

  a = s21_sprintf(str1, format, &n1);
  b = sprintf(str2, format, &n2);
  ck_assert_msg(
      (a == b) && !strcmp(str1, str2),
      "format == \"%s\", a == %d, b == %d, n1 == %d, n2 == %d, str1 == "
      "\"%s\", str2 == \"%s\"",
      format, a, b, n1, n2, str1, str2);

  char *format2 = "%d%n";
  a = s21_sprintf(str1, format2, 12345, &n1);
  b = sprintf(str2, format2, 12345, &n2);
  ck_assert_msg(
      (a == b) && !strcmp(str1, str2),
      "format == \"%s\", a == %d, b == %d, n1 == %d, n2 == %d, str1 == "
      "\"%s\", str2 == \"%s\"",
      format2, a, b, n1, n2, str1, str2);
}
END_TEST

START_TEST(sprintf_7) {
  char str1[BUFFER];
  char str2[BUFFER];
  int a, b;

  a = s21_sprintf(str1, "132%%132");
  b = sprintf(str2, "132%%132");
  ck_assert_msg(
      (a == b) && !strcmp(str1, str2),
      "format == \"%%%%\", a == %d, b == %d, str1 == \"%s\", str2 == \"%s\"", a,
      b, str1, str2);
}

Suite *suite_sprintf() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_sprintf" RESET);
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1);
  tcase_add_test(tc, sprintf_2);
  tcase_add_test(tc, sprintf_3);
  tcase_add_test(tc, sprintf_4);
  tcase_add_test(tc, sprintf_5);
  tcase_add_test(tc, sprintf_6);
  tcase_add_test(tc, sprintf_7);

  suite_add_tcase(s, tc);
  return s;
}
