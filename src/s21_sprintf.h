#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool precision_status;
  int width;
  int precision;
  char lenght;
} flags;

// int s21_sprintf(char *str, const char *format, ...);
int is_int(char a);
const char *get_flags(const char *format, flags *f);
const char *get_width(const char *format, flags *f);
const char *get_precision(const char *format, flags *f);
const char *get_lenght(const char *format, flags *f);
void get_specifier(const char *format, flags f, va_list arg, char *buf);
void char_specifier(flags f, va_list arg, char *buf);
void int_specifier(flags f, va_list arg, char *buf);
void double_specifier(flags f, va_list arg, char *buf);
void string_specifier(flags f, va_list arg, char *buf);
void unsigned_specifier(flags f, va_list arg, char *buf);
void convert_int_char(char *buf, int64_t num, flags f);
void convert_double_char(char *buf, double value, flags f);
void convert_unsigned_char(flags f, char *buf, uint64_t num);
void number_precision(flags f, char *buf);
void string_precision(flags f, char *buf);
void negative_value(char *buf);
void positive_value(char *buf, char val);
void set_width(flags f, char *buf);
void set_minus(flags f, char *buf);

#endif  // SRC_S21_SPRINTF_H_
