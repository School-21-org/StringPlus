#include "s21_string.h"
/*
Appends the string pointed to, by src to the end of the
string pointed to, by dest up to n characters long
*/
char* s21_strncat(char* dest, const char* src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t count = 0;
  for (; count < n && src[count] != '\0'; count++) {
    dest[dest_len + count] = src[count];
  }
  dest[dest_len + count] = '\0';
  return dest;
}