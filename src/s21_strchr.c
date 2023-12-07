/*
| 8	| char *strchr(const char *str, int c) |
| Searches for the first occurrence of the character c (an unsigned char) in the
string pointed to, by the argument str. |
*/

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  s21_size_t len = s21_strlen(str);
  int found = 0;
  char *res = S21_NULL;

  for (s21_size_t i = 0; i <= len; i++) {
    if (!found) {
      if (str[i] == c) {
        res = (char *)str + i;
        found = 1;
      }
    }
  }

  return res;
}
