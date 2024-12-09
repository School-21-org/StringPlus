#include "s21_string.h"
/*
Searches for the first occurrence of the character c (an unsigned char)
in the first n bytes of the string pointed to, by the argument str
*/
void* s21_memchr(const void* str, int c, s21_size_t n) {
  const unsigned char* str_find = str;
  char* result = S21_NULL;
  while ((str_find < (unsigned char*)str + n) && !result) {
    if (*str_find == (unsigned char)c) {
      result = (void*)str_find;
    }
    str_find++;
  }
  return result;
}