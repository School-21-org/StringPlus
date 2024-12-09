#include "s21_string.h"
/*
Computes the length of the string str up to
but not including the terminating null character
*/
s21_size_t s21_strlen(const char* str) {
  s21_size_t count = 0;
  if (str != S21_NULL) {
    while (*str != '\0') {
      count++;
      str++;
    }
  }
  return count;
}