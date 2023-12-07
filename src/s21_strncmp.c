/*
| 10 | int strncmp(const char *str1, const char *str2, s21_size_t n) |
| Compares at most the first n bytes of str1 and str2. |
*/

#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  int found = 0;

  for (s21_size_t i = 0; i < n; i++) {
    if (!found && str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      found = 1;
    }
  }

  return res;
}