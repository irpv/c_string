#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  const char *i = str1;
  int flag = 0;
  while (*i && flag == 0) {
    const char *j = str2;
    while (*j && flag == 0) {
      if (*i == *j) {
        flag = -1;
      }
      j += 1;
    }
    i += 1;
    if (flag == 0) {
      count++;
    }
  }
  return count;
}
