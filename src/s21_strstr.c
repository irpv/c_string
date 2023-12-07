#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int lenH = s21_strlen(haystack);
  int lenS = s21_strlen(needle);
  int flag = 0;
  char *answer = S21_NULL;
  for (int i = 0; (i < lenH) && (flag == 0); i++) {
    int check = 0;
    for (int j = 0; (j < lenS) && (check == 0); j++) {
      if (haystack[j + i] != needle[j]) {
        check = 1;
      }
    }
    if (check == 0) {
      answer = (char *)haystack + i;
      flag = 1;
    }
  }
  if (s21_strlen(haystack) == 0 && s21_strlen(needle) == 0) {
    answer = "";
  }
  return answer;
}
