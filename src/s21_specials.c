#include "s21_string.h"

#define CHAR_REGISTER 32

void* s21_to_upper(const char* str) {
  char* str_result = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len_result = s21_strlen(str);
    str_result = malloc((len_result + 1) * sizeof(char));
    if (str_result != S21_NULL) {
      for (register s21_size_t i = 0; i < len_result; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_result[i] = str[i] - CHAR_REGISTER;
        } else {
          str_result[i] = str[i];
        }
      }
      str_result[len_result] = '\0';
    }
  }
  return str_result;
}

void* s21_to_lower(const char* str) {
  char* str_result = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len_result = s21_strlen(str);
    str_result = malloc((len_result + 1) * sizeof(char));
    if (str_result) {
      for (register s21_size_t i = 0; i < len_result; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_result[i] = str[i] + CHAR_REGISTER;
        } else {
          str_result[i] = str[i];
        }
      }
      str_result[len_result] = '\0';
    }
  }
  return str_result;
}

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* str_result = S21_NULL;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    str_result = (char*)malloc((len_src + len_str + 1) * sizeof(char));
    if (str_result) {
      if (start_index > len_src) {
        start_index = len_src;
      }
      for (register s21_size_t i = 0; i < start_index; i++) {
        str_result[i] = src[i];
      }
      for (register s21_size_t i = 0; i < len_str; i++) {
        str_result[start_index + i] = str[i];
      }
      for (register s21_size_t i = start_index; i < len_src; i++) {
        str_result[start_index + len_str + (i - start_index)] = src[i];
      }
      str_result[len_src + len_str] = '\0';
    }
  } else if (str == S21_NULL && src != S21_NULL) {
    str_result = (char*)malloc((s21_strlen(src) + 1) * sizeof(char));
    if (str_result) s21_strncpy(str_result, src, s21_strlen(src) + 1);
  }
  return str_result;
}

void* s21_trim(const char* src, const char* trim_chars) {
  char* str_result = S21_NULL;
  char* trim_s21 = (char*)trim_chars;
  if (src != S21_NULL) {
    if (trim_chars == S21_NULL || trim_chars[0] == '\0') {
      trim_s21 = " ";
    }
    s21_size_t str_start = 0;
    s21_size_t str_end = s21_strlen(src);
    while (str_start < str_end &&
           (s21_strchr(trim_s21, src[str_start]) != S21_NULL)) {
      str_start++;
    }
    while (str_end > str_start &&
           (s21_strchr(trim_s21, src[str_end]) != S21_NULL)) {
      str_end--;
    }
    s21_size_t len_str_result = str_end - str_start + 1;
    str_result = (char*)malloc(len_str_result + 1);
    if (str_result) {
      s21_memcpy(str_result, src + str_start, len_str_result);
      str_result[len_str_result] = '\0';
    }
  }
  return str_result;
}