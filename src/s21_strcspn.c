#include "s21_string.h"
/*
Calculates the length of the initial segment of str1
which consists entirely of characters not in str2
*/
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  while (len < s21_strlen(str1) && !s21_strchr(str2, str1[len])) {
    len++;
  }
  return len;
}