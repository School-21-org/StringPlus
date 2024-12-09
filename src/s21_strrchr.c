#include "s21_string.h"
/*
Searches for the last occurrence of the character c
(an unsigned char) in the string pointed to by the argument str
*/
char* s21_strrchr(const char* str, int c) {
  char* result = S21_NULL;
  char* str_end = (char*)str + s21_strlen(str);
  if (c == '\0') {
    result = str_end;
  }
  while (str_end >= str && !result) {
    if (*str_end == c) {
      result = str_end;
    }
    str_end--;
  }
  return result;
}