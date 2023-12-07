#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  int R = 0;

  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
      flags f = {0};
      format++;
      char buffer[BUFFER_SIZE] = {'\0'};

      format = get_flags(format, &f);
      format = get_width(format, &f);
      format = get_precision(format, &f);
      format = get_lenght(format, &f);
      get_specifier(format, f, arg, buffer);

      format++;

      set_width(f, buffer);
      set_minus(f, buffer);

      for (int i = 0; buffer[i]; i++, str++) {
        *str = buffer[i];
        R++;
      }
    } else {
      *str++ = *format++;
      R++;
    }
  }

  va_end(arg);
  *str = '\0';
  return R;
}

int is_int(char a) { return (a >= '0' && a <= '9'); }

const char *get_flags(const char *format, flags *f) {
  while (*format == '-' || *format == '+' || *format == ' ') {
    if (*format == '-') f->minus = true;
    if (*format == '+') f->plus = true;
    if (*format == ' ') f->space = true;
    format++;
  }
  return format;
}

const char *get_width(const char *format, flags *f) {
  if (is_int(*format)) {
    char buff[BUFFER_SIZE] = {'\0'};
    for (int i = 0; is_int(*format); i++, format++) {
      buff[i] = *format;
    }
    f->width = atoi(buff);
  }

  return format;
}

const char *get_precision(const char *format, flags *f) {
  if (*format == '.') {
    format++;
    f->precision_status = 1;
    if (is_int(*format)) {
      char buff[BUFFER_SIZE] = {'\0'};

      for (int i = 0; is_int(*format); i++, format++) {
        buff[i] = *format;
      }
      f->precision = atoi(buff);
    }
  }

  return format;
}

const char *get_lenght(const char *format, flags *f) {
  if (*format == 'h') {
    f->lenght = 'h';
    format++;
  } else if (*format == 'l') {
    f->lenght = 'l';
    format++;
  }
  return format;
}

void get_specifier(const char *format, flags f, va_list arg, char *buf) {
  if (*format == 'c') {
    char_specifier(f, arg, buf);
  } else if (*format == 'd' || *format == 'i') {
    int_specifier(f, arg, buf);
  } else if (*format == 'f') {
    double_specifier(f, arg, buf);
  } else if (*format == 's') {
    string_specifier(f, arg, buf);
  } else if (*format == 'u') {
    unsigned_specifier(f, arg, buf);
  } else if (*format == '%') {
    *buf = '%';
  }
}

void char_specifier(flags f, va_list arg, char *buf) {
  if (f.lenght == 'l') {
    wchar_t value = va_arg(arg, wchar_t);
    *buf = (wchar_t)value;
  } else {
    char value = va_arg(arg, int);
    *buf = (char)value;
  }
}

void int_specifier(flags f, va_list arg, char *buf) {
  int64_t num = va_arg(arg, int64_t);

  switch (f.lenght) {
    case 0:
      num = (int32_t)num;
      break;
    case 'h':
      num = (int16_t)num;
      break;
  }
  convert_int_char(buf, num, f);
}

void double_specifier(flags f, va_list arg, char *buf) {
  double value = va_arg(arg, double);

  if (f.precision == 0 && f.precision_status == 0) {
    f.precision = 6;
  }

  convert_double_char(buf, value, f);
}

void string_specifier(flags f, va_list arg, char *buf) {
  if (f.lenght == 'l') {
    wchar_t *w_value = va_arg(arg, wchar_t *);
    char value[BUFFER_SIZE] = {'\0'};
    char *buf_buf = buf;

    wcstombs(value, w_value, BUFFER_SIZE);
    for (int i = 0; value[i] != '\0'; i++) {
      *buf++ = value[i];
    }
    string_precision(f, buf_buf);
  } else {
    char *value = va_arg(arg, char *);
    char *buf_buf = buf;

    while (*value) {
      *buf++ = *value++;
    }
    string_precision(f, buf_buf);
  }
}

void unsigned_specifier(flags f, va_list arg, char *buf) {
  uint64_t num = va_arg(arg, uint64_t);

  switch (f.lenght) {
    case 0:
      num = (uint32_t)num;
      break;
    case 'h':
      num = (uint16_t)num;
      break;
  }
  convert_unsigned_char(f, buf, num);
}

void convert_int_char(char *buf, int64_t num, flags f) {
  int i = 0;
  bool neg = 0;

  if (num < 0) {
    neg = 1;
    num *= -1;
  }
  while (num > 9) {
    buf[i++] = (num % 10) + '0';
    num /= 10;
  }
  buf[i++] = num + '0';
  buf[i] = '\0';

  for (int j = 0; j < i / 2; j++) {
    char buff = buf[j];
    buf[j] = buf[i - 1 - j];
    buf[i - 1 - j] = buff;
  }

  number_precision(f, buf);
  if (neg) {
    negative_value(buf);
  } else if (f.plus) {
    positive_value(buf, '+');
  } else if (f.space) {
    positive_value(buf, ' ');
  }
}

void convert_double_char(char *buf, double num, flags f) {
  double double_before_point, double_after_point;
  long long int_after_point = 0;
  int index = 0;
  bool neg = 0;

  if (num < 0) {
    neg = 1;
    num *= -1;
  }

  double_after_point = modf(num, &double_before_point);
  if (f.precision) {
    buf[index++] = '.';
  }

  long long int int_before_point = double_before_point;

  while (int_before_point > 9) {
    buf[index++] = (int_before_point % 10) + '0';
    int_before_point /= 10;
  }
  buf[index++] = int_before_point + '0';

  for (int k = 0; k < index / 2; k++) {
    char buff = buf[k];
    buf[k] = buf[index - 1 - k];
    buf[index - 1 - k] = buff;
  }

  char after_buf[BUFFER_SIZE] = {'\0'};

  for (int i = 0; i < f.precision; i++) {
    double_after_point *= 10;
  }

  int_after_point = round(double_after_point);

  for (int j = 0; j < f.precision; j++) {
    after_buf[j] = (int_after_point % 10) + '0';
    int_after_point /= 10;
  }

  for (int j = f.precision - 1; j >= 0; j--) {
    buf[index++] = after_buf[j];
  }

  if (neg) {
    negative_value(buf);
  } else if (f.plus) {
    positive_value(buf, '+');
  } else if (f.space) {
    positive_value(buf, ' ');
  }
}

void convert_unsigned_char(flags f, char *buf, uint64_t num) {
  int i = 0, j = 0;

  while (num > 9) {
    buf[i++] = (num % 10) + '0';
    num /= 10;
  }
  buf[i++] = num + '0';
  buf[i] = '\0';

  for (; j < i / 2; j++) {
    char buff = buf[j];
    buf[j] = buf[i - 1 - j];
    buf[i - 1 - j] = buff;
  }
  number_precision(f, buf);
}

void number_precision(flags f, char *buf) {
  if (f.precision && (f.precision > (int)s21_strlen(buf))) {
    long unsigned int lenght = f.precision - s21_strlen(buf);
    char buf_buf[BUFFER_SIZE] = {'\0'};

    for (long unsigned int i = 0; i < s21_strlen(buf); i++) {
      buf_buf[i] = buf[i];
    }

    for (long unsigned int i = 0; i < lenght; i++) {
      buf[i] = '0';
    }

    for (long unsigned int i = 0; i < s21_strlen(buf); i++, lenght++) {
      buf[lenght] = buf_buf[i];
    }
  }
}

void string_precision(flags f, char *buf) {
  if (f.precision_status) {
    int i = f.precision;

    while (buf[i] != '\0') {
      buf[i] = '\0';
      i++;
    }
  }
}

void negative_value(char *buf) {
  char buff = '-';

  for (long unsigned int i = 0; i < s21_strlen(buf) + 1; i++) {
    char k = buf[i];
    buf[i] = buff;
    buff = k;
  }
}

void positive_value(char *buf, char val) {
  char buff = val;

  for (long unsigned int i = 0; i < s21_strlen(buf) + 1; i++) {
    char k = buf[i];
    buf[i] = buff;
    buff = k;
  }
}

void set_width(flags f, char *buf) {
  if (f.width > (int)s21_strlen(buf) && !f.minus) {
    char buf_buf[BUFFER_SIZE] = {'\0'};
    int width = f.width - (int)s21_strlen(buf);

    for (unsigned long int i = 0; i < s21_strlen(buf); i++) {
      buf_buf[i] = buf[i];
    }

    for (int i = 0; i < width; i++) {
      buf[i] = ' ';
    }

    for (int i = width, j = 0; buf[j] != '\0'; i++, j++) {
      buf[i] = buf_buf[j];
    }
  }
}

void set_minus(flags f, char *buf) {
  if (f.width > (int)s21_strlen(buf) && f.minus) {
    int lenght = (int)s21_strlen(buf);

    while (lenght < f.width) {
      buf[lenght] = ' ';
      lenght++;
    }
  }
}
