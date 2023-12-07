#include "./s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int flag = 1;
  char *point = (char *)str;
  char *place = S21_NULL;
  while (flag && (str != S21_NULL) && (n--)) {
    if (*point != c) {
      point++;
    } else {
      place = point;
      flag = 0;
    }
  }
  return place;
}
