#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  const char *i = str1;
  int flag = 0;
  while (*i && flag == 0) {
    int match = 0;
    const char *j = str2;
    while (*j && flag == 0) {
      if (*i == *j) {
        match = 1;
      }
      j += 1;
    }
    if (!match) {
      flag = 1;
    }
    i += 1;
    if (match == 1) {
      count++;
    }
  }
  return count;
}
