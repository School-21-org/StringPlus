#include "s21_string.h"
/*
Copies up to n characters from the string pointed to, by src to dest
*/
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int null_sumbol = 1;
  for (s21_size_t i = 0; i < n; i++) {
    if (src[i] == '\0') null_sumbol = 0;
    if (null_sumbol) dest[i] = src[i];
    if (!null_sumbol) dest[i] = '\0';
  }
  return dest;
}