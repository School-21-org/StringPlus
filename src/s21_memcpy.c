#include "s21_string.h"
/*
Copies n characters from src to dest
*/
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *p_dest = dest;
  const char *p_src = src;
  while (n--) {
    *(char *)p_dest = *(char *)p_src;
    p_src++;
    p_dest++;
  }
  return dest;
}