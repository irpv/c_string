/*
| 7 | char *strncat(char *dest, const char *src, s21_size_t n) |
| Appends the string pointed to, by src to the end of the string pointed to, by
dest up to n characters long. |
*/

#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = s21_strlen(dest);
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[len + i] = src[i];
    i += 1;
  }
  dest[len + i] = '\0';

  return dest;
}
