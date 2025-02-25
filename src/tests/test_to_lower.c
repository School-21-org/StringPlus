#include "s21_test.h"

char* to_lower_c(char* s) {
  for (char* p = s; *p; p++) {
    *p = tolower(*p);
  }
  return s;
}

START_TEST(hello_world_diy_func) {
  const char str_origin[20] = "Hello, WoRlD!";
  char* str_2 = (char*)str_origin;
  char* str_to_upper_c = to_lower_c(str_2);
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_to_upper_c);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(hello_world_str) {
  const char str_origin[20] = "Hello, WoRlD!";
  const char str_check[20] = "hello, world!";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(empty_string_diy_func) {
  const char str_origin[20] = "";
  char* str_2 = (char*)str_origin;
  char* str_to_upper_c = to_lower_c(str_2);
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_to_upper_c);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(empty_string_str) {
  const char str_origin[20] = "";
  const char str_check[20] = "";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(end_symb_inside_string_diy_func) {
  const char str_origin[20] = "Hello\0WoRlD!";
  char* str_2 = (char*)str_origin;
  char* str_to_upper_c = to_lower_c(str_2);
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_to_upper_c);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(end_symb_inside_string_str) {
  const char str_origin[20] = "Hello\0WoRlD!";
  const char str_check[20] = "hello";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(num) {
  const char str_origin[20] = "123456789";
  const char str_check[20] = "123456789";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(end_symb) {
  const char str_origin[20] = "\0";
  const char str_check[20] = "\0";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(spaces) {
  const char str_origin[20] = "    ";
  const char str_check[20] = "    ";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

START_TEST(chars_spaces_nums) {
  const char str_origin[25] = "HelLo, 123 123 wOrLd!";
  const char str_check[25] = "hello, 123 123 world!";
  char* str_s21_to_lower = s21_to_lower(str_origin);
  ck_assert_str_eq(str_s21_to_lower, str_check);
  free(str_s21_to_lower);
}
END_TEST

Suite* suite_to_lower() {
  Suite* suite = suite_create("suite_to_lower");
  TCase* tcase = tcase_create("tcase_to_lower");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, hello_world_str);
  tcase_add_test(tcase, empty_string_str);
  tcase_add_test(tcase, chars_spaces_nums);
  tcase_add_test(tcase, hello_world_diy_func);
  tcase_add_test(tcase, empty_string_diy_func);
  tcase_add_test(tcase, end_symb_inside_string_str);
  tcase_add_test(tcase, end_symb_inside_string_diy_func);

  suite_add_tcase(suite, tcase);

  return suite;
}