/*
| 15 | s21_size_t strlen(const char *str) |
| Computes the length of the string str up to but not including the terminating
null character. |
*/

#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  const char **p = &str;

  while (**p != '\0') {
    len += 1;
    *p += 1;
  }

  return len;
}
