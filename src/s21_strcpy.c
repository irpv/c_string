#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *p = dest;
  const char *s = src;
  while ((*p = *s)) {
    *p++ = *s++;
  }
  return dest;
}
