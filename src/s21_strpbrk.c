#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
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
    if (flag == 0) {
      i += 1;
    }
  }
  if (!(*i)) {
    i = S21_NULL;
  }
  return (char *)i;
}
