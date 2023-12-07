#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *s = S21_NULL;

  if (str) {
    s21_size_t len = s21_strlen(str);
    s = malloc((len + 1) * sizeof(char));

    if (s) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
          s[i] = str[i] - 32;
        } else {
          s[i] = str[i];
        }
      }
      s[len] = '\0';
    }
  }

  return s;
}

void *s21_to_lower(const char *str) {
  char *s = S21_NULL;

  if (str) {
    s21_size_t len = s21_strlen(str);
    s = malloc((len + 1) * sizeof(char));

    if (s) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
          s[i] = str[i] + 32;
        } else {
          s[i] = str[i];
        }
      }
      s[len] = '\0';
    }
  }

  return s;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;

  if (src && str) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);

    s21_size_t len_res = len_src + len_str;

    if (start_index <= len_src) {
      res = malloc((len_res + 1) * sizeof(char));

      if (res) {
        s21_size_t a = 0, b = 0;

        for (s21_size_t i = 0; i <= len_res; i++) {
          if (i < start_index || !str[b]) {
            res[i] = src[a++];
          } else {
            res[i] = str[b++];
          }
          res[len_res] = '\0';
        }
      }
    }
  }

  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;

  if (src && trim_chars) {
    s21_size_t len = s21_strlen(src);
    res = malloc((len + 1) * sizeof(char));

    if (res) {
      s21_strcpy(res, src);

      for (int i = len - 1;
           i >= 0 && s21_strrchr(trim_chars, res[i]) != S21_NULL; i--) {
        res[i] = '\0';
      }

      while (res[0] != '\0' && s21_strrchr(trim_chars, res[0]) != S21_NULL) {
        s21_memmove(&res[0], &res[1], len);
      }
    }
  } else {
    if (src) {
      res = s21_trim(src, "\t\n");
    }
  }

  return res;
}
