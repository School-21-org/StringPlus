#include "s21_string.h"
/*
Searches for the first occurrence of the character
c (an unsigned char) in the string pointed to, by the argument str
*/
char* s21_strchr(const char* str, int c) {
  char* result = S21_NULL;
  char* str_start = (char*)str;
  char* str_end = str_start + s21_strlen(str);
  if (c == '\0') {
    result = str_end;
  }
  while (str_start < str_end && !result) {
    if (*str_start == c) {
      result = str_start;
    }
    str_start++;
  }
  return result;
}