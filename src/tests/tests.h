#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

#define RESET "\x1b[0m"
#define YELLOW_BG "\x1b[43m"
#define BLACK "\x1b[30m"

#define RED_BG "\x1b[41m"
#define GREEN_BG "\x1b[42m"
#define WHITE_BG "\x1b[47m"

Suite *suite_to_lower();
Suite *suite_to_upper();
Suite *suite_trim();
Suite *suite_insert();
Suite *suite_memchr();
Suite *suite_memcmp();
Suite *suite_memcpy();
Suite *suite_memmove();
Suite *suite_memset();
Suite *suite_strcat();
Suite *suite_strchr();
Suite *suite_strcmp();
Suite *suite_strcpy();
Suite *suite_strcspn();
Suite *suite_strerror();
Suite *suite_strlen();
Suite *suite_strncat();
Suite *suite_strncmp();
Suite *suite_strncpy();
Suite *suite_strpbrk();
Suite *suite_strrchr();
Suite *suite_strspn();
Suite *suite_strstr();
Suite *suite_strtok();
Suite *suite_sprintf();

void run();

#endif  // SRC_TESTS_TESTS_H_
