#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *token;
  static char *prevs = S21_NULL;

  if (str || prevs) {
    if (str == S21_NULL) {
      str = prevs;
    }
    str += s21_strspn(str, delim);
    if (*str == '\0') {
      prevs = str;
      token = S21_NULL;
    } else {
      token = str;
      str = s21_strpbrk(token, delim);
      if (str == S21_NULL) {
        prevs = s21_strchr(token, '\0');
      } else {
        *str = '\0';
        prevs = str + 1;
      }
    }
  } else {
    token = S21_NULL;
  }
  return token;
}
