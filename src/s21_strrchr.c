#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *i = S21_NULL;
  s21_size_t length = s21_strlen(str);
  int check = length;
  int flag = 0;
  for (; ((check >= 0) && (flag == 0)); check--) {
    if (str[check] == c) {
      i = (char *)str + check;
      flag = -1;
    }
  }
  return i;
}
