#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d_tmp = (char *)dest;
  char *s_tmp = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    *d_tmp++ = *s_tmp++;
  }
  return (char *)dest;
}
