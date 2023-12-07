#include "./s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *str1_tmp = (char *)str1;
  const char *str2_tmp = (char *)str2;
  int result = 0;
  int flag = 1;

  for (s21_size_t i = 0; flag && i < n; i++) {
    if (str1_tmp[i] != str2_tmp[i]) {
      result = str1_tmp[i] - str2_tmp[i];
      flag = 0;
    }
  }
  return result;
}
