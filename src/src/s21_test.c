//  Copyright 2022 inglorious basters

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./s21_string.h"
#include <limits.h>
#include <check.h>

//  BOYCEING ****************************************

//  s21_memcpy

START_TEST(s21_memcpy_normal) {
    char test_dest[100] = "hello world again!";
    char test_dest2[100] = "hello world again!";
    const char *test_src = "tak";
    s21_size_t test_count = 3;
    char *s21_res = s21_memcpy(test_dest, test_src, test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
} END_TEST

START_TEST(s21_memcpy_out) {
    char test_dest[100] = "hello world again!";
    char test_dest2[100] = "hello world again!";
    const char *test_src = "tak";
    s21_size_t test_count = 5;
    char *s21_res = s21_memcpy(test_dest, test_src, test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
} END_TEST

START_TEST(s21_memcpy_empty_dest) {
    char test_dest[100] = "";
    char test_dest2[100] = "";
    const char *test_src = "tak";
    s21_size_t test_count = 3;
    char *s21_res = s21_memcpy(test_dest, test_src, test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
} END_TEST

START_TEST(s21_memcpy_empty_src) {
    char test_dest[100] = "hello world";
    char test_dest2[100] = "hello world";
    const char *test_src = "";
    s21_size_t test_count = 3;
    char *s21_res = s21_memcpy(test_dest, test_src, test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
} END_TEST

//  s21_memmove

START_TEST(s21_memmove_normal) {
    char test_dest[100] = "hello world again! and again";
    char test_dest2[100] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    s21_size_t test_count = 3;
    char *s21_res = s21_memmove(test_dest, test_src, test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
} END_TEST

START_TEST(s21_memmove_with_index) {
    char test_dest[100] = "hello world again! and again";
    char test_dest2[100] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    s21_size_t test_count = 3;
    char *s21_res = s21_memmove(test_dest, &test_src[3], test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, &test_src[3], test_count));
} END_TEST

START_TEST(s21_memmove_with_index_both) {
    char test_dest[100] = "hello world again! and again";
    char test_dest2[100] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    s21_size_t test_count = 3;
    char *s21_res = s21_memmove(&test_dest[1], &test_src[3], test_count);
    ck_assert_str_eq(s21_res, memcpy(&test_dest2[1], &test_src[3], test_count));
} END_TEST

START_TEST(s21_memmove_out) {
    char test_dest[100] = "hello world again! and again";
    char test_dest2[100] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    s21_size_t test_count = 4;
    char *s21_res = s21_memmove(test_dest, test_src, test_count);
    ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
} END_TEST

START_TEST(s21_memmove_dest_short) {
    char test_dest[50] = "hello world again! and again";
    char test_dest2[50] = "hello world again! and again";
    s21_size_t test_count = 3;
    char *s21_res = s21_memmove(&test_dest[5], &test_dest[2], test_count);
    ck_assert_str_eq(s21_res, memcpy(&test_dest2[5], &test_dest2[2], test_count));
} END_TEST

//  s21_strcpy

START_TEST(s21_strcpy_normal) {
    char test_dest[100] = "hello world again! and again";
    char test_dest2[100] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    char *s21_res = s21_strcpy(test_dest, test_src);
    ck_assert_str_eq(s21_res, strcpy(test_dest2, test_src));
} END_TEST

START_TEST(s21_strcpy_out) {
    char test_dest[50] = "hello world again! and again";
    char test_dest2[50] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    char *s21_res = s21_strcpy(test_dest, test_src);
    ck_assert_str_eq(s21_res, strcpy(test_dest2, test_src));
} END_TEST

//  s21_strncpy

START_TEST(s21_strncpy_normal) {
    char test_dest[100] = "Hello world gello world gellortwls";
    char test_dest2[100] = "Hello world gello world gellortwls";
    const char test_src[100] = "taktaktak";
    s21_size_t n = 5;
    char *s21_res = s21_strncpy(test_dest, test_src, n);
    ck_assert_str_eq(s21_res, strncpy(test_dest2, test_src, n));
} END_TEST

START_TEST(s21_strncpy_out) {
    char test_dest[50] = "hello world again! and again";
    char test_dest2[50] = "hello world again! and again";
    const char test_src[100] = "taktaktak";
    s21_size_t n = 10;
    char *s21_res = s21_strncpy(test_dest, test_src, n);
    ck_assert_str_eq(s21_res, strncpy(test_dest2, test_src, n));
} END_TEST

//  s21_insert

START_TEST(s21_insert_normal) {
    char *src = "lol cho";
    char *str = "nie rozumiem ";
    s21_size_t start_index = 4;

    char *func_result0 = s21_insert(src, str, start_index);
    ck_assert_str_eq(func_result0, "lol nie rozumiem cho");
    free(func_result0);
} END_TEST

START_TEST(s21_insert_empty_src) {
    char *src = "";
    char *str = "nie rozumiem ";
    s21_size_t start_index = 4;

    char *func_result0 = s21_insert(src, str, start_index);
    ck_assert_ptr_eq(func_result0, s21_NULL);
    free(func_result0);
} END_TEST

START_TEST(s21_insert_empty_str) {
    char *src = "lol cho";
    char *str = "";
    s21_size_t start_index = 4;

    char *func_result0 = s21_insert(src, str, start_index);
    ck_assert_ptr_eq(func_result0, s21_NULL);
    free(func_result0);
} END_TEST

START_TEST(s21_insert_invalid_index) {
    char *src = "lol cho";
    char *str = "nie rozumiem";
    s21_size_t start_index1 = 1000;
    s21_size_t start_index2 = -2;

    char *func_result1 = s21_insert(src, str, start_index1);
    char *func_result2 = s21_insert(src, str, start_index2);

    ck_assert_ptr_eq(func_result1, s21_NULL);
    ck_assert_ptr_eq(func_result2, s21_NULL);
    free(func_result1);
    free(func_result2);
} END_TEST

//  HARMONIC ****************************************

START_TEST(s21_to_upper_normal) {
    char* test_str0 = "hello world";
    char* test_str1 = "h1e2l3l4o5";

    char* func_result0 = s21_to_upper(test_str0);
    char* func_result1 = s21_to_upper(test_str1);

    ck_assert_str_eq(func_result0, "HELLO WORLD");
    ck_assert_str_eq(func_result1, "H1E2L3L4O5");
    free(func_result0);
    free(func_result1);
} END_TEST

//  s21_to_upper
START_TEST(s21_to_upper_whith_sign) {
    char* test_str = "h!e1l/l&o.";

    char* func_result = s21_to_upper(test_str);
    ck_assert_str_eq(func_result, "H!E1L/L&O.");
    free(func_result);
} END_TEST

START_TEST(s21_to_upper_whith_upper) {
    char* test_str = "HELLO";

    char* func_result = s21_to_upper(test_str);
    ck_assert_str_eq(func_result, test_str);
    free(func_result);
} END_TEST

START_TEST(s21_to_upper_empty_string) {
    char* test_str0 = "";

    char* func_result = s21_to_upper(test_str0);
    ck_assert_ptr_eq(func_result, s21_NULL);
    free(func_result);
} END_TEST

//  s21_strtok
START_TEST(s21_strtok_normal) {
    char s21_test_str[30] = "one/two.three?four";
    char lib_test_str[30] = "one/two.three?four";
    char* step = "./?";
    char* s21_result = s21_strtok(s21_test_str, step);
    char* lib_result = strtok(lib_test_str, step);

    while (s21_result != s21_NULL && lib_result != s21_NULL) {
        ck_assert_str_eq(s21_result, lib_result);
        s21_result = s21_strtok(s21_NULL, step);
        lib_result = strtok(s21_NULL, step);
    }
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strtok_no_delimetr) {
    char s21_test_str[30] = "one/two.three?four";
    char lib_test_str[30] = "one/two.three?four";
    char* step = "$()-";
    char* s21_result = s21_strtok(s21_test_str, step);
    char* lib_result = strtok(lib_test_str, step);

    while (s21_result != s21_NULL && lib_result != s21_NULL) {
        ck_assert_str_eq(s21_result, lib_result);
        s21_result = s21_strtok(s21_NULL, step);
        lib_result = strtok(s21_NULL, step);
    }
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strtok_empty) {
    char s21_test_str[30] = "";
    char lib_test_str[30] = "";
    char* step = "$()-";
    char* s21_result = s21_strtok(s21_test_str, step);
    char* lib_result = strtok(lib_test_str, step);

    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

//  s21_strpbrk
START_TEST(s21_strpbrk_normal) {
    char test_str[11] = "0123456789";
    char symb[3] = "345";

    char* s21_result = s21_strpbrk(test_str, symb);
    char* lib_result = strpbrk(test_str, symb);

    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strpbrk_no_symb) {
    char test_str[11] = "0123456789";
    char symb[1] = "a";

    char* s21_result = s21_strpbrk(test_str, symb);
    char* lib_result = strpbrk(test_str, symb);

    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strpbrk_empty_symb) {
    char test_str[11] = "0123456789";
    char* symb = "";

    char* s21_result = s21_strpbrk(test_str, symb);
    char* lib_result = strpbrk(test_str, symb);

    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strpbrk_empty_str) {
    char* test_str = "";
    char symb[3] = "123";

    char* s21_result = s21_strpbrk(test_str, symb);
    char* lib_result = strpbrk(test_str, symb);

    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

//  memset
START_TEST(s21_memset_normal) {
    char s21_test_str[10] = "Hello";
    s21_memset(s21_test_str, 'c', 3);
    char lib_test_str[10] = "Hello";
    memset(lib_test_str, 'c', 3);

    ck_assert_str_eq(s21_test_str, lib_test_str);
} END_TEST

START_TEST(s21_memset_null) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 12);
    char* lib_test_str = (char*)malloc(sizeof(char) * 12);

    s21_memset(s21_test_str, '\0', 11);
    memset(lib_test_str, '\0', 11);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_memset_sign) {
    char s21_test_str[10] = "Hello";
    char lib_test_str[10] = "Hello";
    s21_memset(s21_test_str, 0, 5);
    memset(lib_test_str, 0, 5);
    ck_assert_str_eq(s21_test_str, lib_test_str);
} END_TEST

//  strerror
START_TEST(s21_strerror_normal) {
    char* s21_test_str = s21_strerror(S21_E2BIG);
    char* lib_test_str = strerror(E2BIG);

    ck_assert_str_eq(s21_test_str, lib_test_str);
} END_TEST

//  sprintf
START_TEST(s21_sprintf_d) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int min = -2147483648;
    int max = 2147483647;

    int lib_res = sprintf(lib_test_str,
        "|%d| |%d| |% d| |%+d| |%d| |%-5d| |%05d| |%+05d| |%05d| |%20.15d| |%+.0d| |%5.15d|\n",
        12, 0, 12, max, min, 12, 12, 12, -12, 12, 12, -12);
    int s21_res = s21_sprintf(s21_test_str,
        "|%d| |%d| |% d| |%+d| |%d| |%-5d| |%05d| |%+05d| |%05d| |%20.15d| |%+.0d| |%5.15d|\n",
        12, 0, 12, max, min, 12, 12, 12, -12, 12, 12, -12);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_i) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    int lib_res = sprintf(lib_test_str,
        "|%i| |% i| |%+i| |%i| |%-5i| |%05i| |%+05i| |%05i|\n",
        12, 12, 12, -12, 12, 12, 12, -12);
    int s21_res = s21_sprintf(s21_test_str,
        "|%i| |% i| |%+i| |%i| |%-5i| |%05i| |%+05i| |%05i|\n",
        12, 12, 12, -12, 12, 12, 12, -12);
    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_star) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    int lib_res = sprintf(lib_test_str, "%*.*d\n", 5, 3, 5);
    int s21_res = s21_sprintf(s21_test_str, "%*.*d\n", 5, 3, 5);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_u) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    unsigned int u = 2147483647;
    unsigned int a = 0;
    unsigned int b = 102;
    unsigned int c = 12;
    unsigned int d = 120;
    unsigned int e = 1200;
    unsigned int f = 14895085;
    int lib_res = sprintf(lib_test_str,
        "|%u| |%u| |%u| |%-20u| |%u| |%07u| |%05u| |%.20u| |%-20.15u| |%u|\n", u,
        a, b, c, f, c, c, c, d, e);
    int s21_res = s21_sprintf(s21_test_str,
        "|%u| |%u| |%u| |%-20u| |%u| |%07u| |%05u| |%.20u| |%-20.15u| |%u|\n", u,
        a, b, c, f, c, c, c, d, e);
    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);
    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_f) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int lib_res = sprintf(lib_test_str,
        "|%f| |% f| |%+f| |%f| |%-8f| |%08f| |%+08f| |%08f|\n",
        0.020, 0.020, 0.020, -0.020, 0.020, 0.020, 0.020, -0.020);
    int s21_res = s21_sprintf(s21_test_str,
        "|%f| |% f| |%+f| |%f| |%-8f| |%08f| |%+08f| |%08f|\n",
        0.020, 0.020, 0.020, -0.020, 0.020, 0.020, 0.020, -0.020);
    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);
    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_eE) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    int lib_res = sprintf(lib_test_str,
        "|%e| |% E| |%+e| |%E| |%-8e| |%08E| |%+08E| |%08e|\n",
        0.020, 0.020, 0.020, -344.020, 344.020, 344.020, 344.020, -344.020);
    int s21_res = s21_sprintf(s21_test_str,
        "|%e| |% E| |%+e| |%E| |%-8e| |%08E| |%+08E| |%08e|\n",
        0.020, 0.020, 0.020, -344.020, 344.020, 344.020, 344.020, -344.020);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_o) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int i = 2147483647;

    int lib_res = sprintf(lib_test_str,
        "|%o| |%#o| |%#o| |%o| |%8o| |%#015o| |%-15o| |%#-15o|\n",
        286546, 0, i, 286546, 286546, 286546, 286546, 286546);
    int s21_res = s21_sprintf(s21_test_str,
        "|%o| |%#o| |%#o| |%o| |%8o| |%#015o| |%-15o| |%#-15o|\n",
        286546, 0, i, 286546, 286546, 286546, 286546, 286546);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST


START_TEST(s21_sprintf_xX) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int i = 2147483647;

    int lib_res = sprintf(lib_test_str,
        "|%x| |%#x| |%012x| |%x| |%-8X| |%08X| |%#08X| |%#20X|\n",
        286546, 0, i, 286546, 286546, 286546, 286546, 286546);
    int s21_res = s21_sprintf(s21_test_str,
        "|%x| |%#x| |%012x| |%x| |%-8X| |%08X| |%#08X| |%#20X|\n",
        286546, 0, i, 286546, 286546, 286546, 286546, 286546);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_gG) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int lib_res = sprintf(lib_test_str,
        "|%.2g| |%12.4G| |%-15.5g| |%+5.15g| |%015.13g| |%#15.3g| |%+#10.3G| |%10.0G| |%10.0G|",
        45333.200000, 123245.21324, 1.21324, 0.0, -123245.21324, 453.205, 453.205, 453.205, 453.205);
    int s21_res = s21_sprintf(s21_test_str,
        "|%.2g| |%12.4G| |%-15.5g| |%+5.15g| |%015.13g| |%#15.3g| |%+#10.3G| |%10.0G| |%10.0G|",
        45333.200000, 123245.21324, 1.21324, 0.0, -123245.21324, 453.205, 453.205, 453.205, 453.205);
    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);
    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_p) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int i = 2147483647;
    int a;
    int b;
    char c;
    int lib_res = sprintf(lib_test_str, "|%p| |%20p| |%p| |%-15p| |%p|\n", &i, &a, &b, &c, &i);
    int s21_res = s21_sprintf(s21_test_str, "|%p| |%20p| |%p| |%-15p| |%p|\n", &i, &a, &b, &c, &i);
    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);
    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_s) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    int lib_res = sprintf(lib_test_str, "|%20s| |%-20s| |%5.0s| |%.1s|\n", "Hi", "My", "Hi", "My");
    int s21_res = s21_sprintf(s21_test_str, "|%20s| |%-20s| |%5.0s| |%.1s|\n", "Hi", "My", "Hi", "My");

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_h) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    unsigned short i = 0;
    unsigned short a = 32767;
    short e = 0;
    short f = 32767;
    unsigned short b = 65535;
    unsigned long c = 4294967295;
    int lib_res = sprintf(lib_test_str, "|%hi| |%hd| |%ho| |%hu| |%hx| |%hX| |%lX|", e, f, b, i, a, b, c);
    int s21_res = s21_sprintf(s21_test_str, "|%hi| |%hd| |%ho| |%hu| |%hx| |%hX| |%lX|", e, f, b, i, a, b, c);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_l) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    long i = LONG_MAX;
    long a = LONG_MIN;
    unsigned long b = 4294967295;
    int lib_res = sprintf(lib_test_str, "|%li| |%ld| |%lo| |%lu| |%lx| |%lX|", i, a, b, b, b, b);
    int s21_res = s21_sprintf(s21_test_str, "|%li| |%ld| |%lo| |%lu| |%lx| |%lX|", i, a, b, b, b, b);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_L) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    long double i = 12345675.12345678;

    int lib_res = sprintf(lib_test_str, "|%Le| |%LE| |%Lf| |%Lg| |%LG| ", i, i, i, i, i);
    int s21_res = s21_sprintf(s21_test_str, "|%Le| |%LE| |%Lf| |%Lg| |%LG| ", i, i, i, i, i);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_n) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);
    int size_s211;
    int size_lib1;
    int size_s212;
    int size_lib2;
    int size_s213;
    int size_lib3;

    int s21_res = s21_sprintf(s21_test_str, "%nHel%%lo%n world%n\n", &size_s211, &size_s212, &size_s213);
        int lib_res = sprintf(lib_test_str, "%nHel%%lo%n world%n\n", &size_lib1, &size_lib2, &size_lib3);

    ck_assert_int_eq(size_s211, size_lib1);
    ck_assert_int_eq(size_s212, size_lib2);
    ck_assert_int_eq(size_s213, size_lib3);
    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);
    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_diu_whith_str) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    long number = 100000000;
    unsigned int a = 1;
        short number1 = 5;
    int lib_res = sprintf(lib_test_str,
        "%d Hello, %010u it's a great % hd, %-10i, %d, %+10d, %ld\n", 0, a, number1, 3, -4, 5, number);
    int s21_res = s21_sprintf(s21_test_str,
        "%d Hello, %010u it's a great % hd, %-10i, %d, %+10d, %ld\n", 0, a, number1, 3, -4, 5, number);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_cs) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 256);
    char* lib_test_str = (char*)malloc(sizeof(char) * 256);

    char* str0 = "User";
    char* str1 = "";
    int lib_res = sprintf(lib_test_str, "Hello, %-13s, i%c, %s a great day!", str0, 't', str1);
    int s21_res = s21_sprintf(s21_test_str, "Hello, %-13s, i%c, %s a great day!", str0, 't', str1);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_f_with_str) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 512);
    char* lib_test_str = (char*)malloc(sizeof(char) * 512);

    int lib_res = sprintf(lib_test_str,
        "Hello%0.10f, my %0.2f, beautiful %+10.f,world %-5.3f", 0.2, 0.12345, 0.3, -0.23246);
    int s21_res = s21_sprintf(s21_test_str,
        "Hello%0.10f, my %0.2f, beautiful %+10.f,world %-5.3f", 0.2, 0.12345, 0.3, -0.23246);

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_empty) {
    char* s21_test_str = (char*)malloc(sizeof(char) * 512);
    char* lib_test_str = (char*)malloc(sizeof(char) * 512);

    int lib_res = sprintf(lib_test_str, "%c", '\0');
    int s21_res = s21_sprintf(s21_test_str, "%c", '\0');

    ck_assert_str_eq(s21_test_str, lib_test_str);
    ck_assert_int_eq(s21_res, lib_res);

    free(s21_test_str);
    free(lib_test_str);
} END_TEST


//  PEVERELL ****************************************

//  s21_size_t s21_strlen(const char *str)
START_TEST(s21_strlen_normal) {
    // Arrange
    char *test_str = "12345678";
    // Act
    int s21_result = s21_strlen(test_str);
    int lib_result = strlen(test_str);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strlen_empty) {
    char *test_str = "";

    int s21_result = s21_strlen(test_str);
    int lib_result = strlen(test_str);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

// s21_strstr
START_TEST(s21_strstr_normal) {
    char *test_haystack = "12345678";
    char *test_needle = "3";

    char *s21_result = s21_strstr(test_haystack, test_needle);
    char *lib_result = strstr(test_haystack, test_needle);

    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strstr_SF) {
    char *test_haystack = "67878";
    char *test_needle = "345";

    char *s21_result = s21_strstr(test_haystack, test_needle);
    char *lib_result = strstr(test_haystack, test_needle);

    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strstr_empty) {
    char *test_haystack = "123456";
    char *test_needle = "";

    char *s21_result = s21_strstr(test_haystack, test_needle);
    char *lib_result = strstr(test_haystack, test_needle);

    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strstr_all_empty) {
    char *test_haystack = "";
    char *test_needle = "";

    char *s21_result = s21_strstr(test_haystack, test_needle);
    char *lib_result = strstr(test_haystack, test_needle);

    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

// int     s21_strcmp(const char *str1, const char *str2)
START_TEST(s21_strcmp_normal_plus) {
    char *test_str = "12346";
    char *test_substr = "12345";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcmp_normal_minus) {
    char *test_str = "12345";
    char *test_substr = "12346";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcmp_empty) {
    char *test_str = "12345";
    char *test_substr = "";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcmp_all_empty) {
    char *test_str = "";
    char *test_substr = "";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcmp_midle_dif_plus) {
    char *test_str = "12845";
    char *test_substr = "12345";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcmp_midle_dif_minus) {
    char *test_str = "12345";
    char *test_substr = "12845";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcmp_equal) {
    char *test_str = "12345";
    char *test_substr = "12345";

    int s21_result = s21_strcmp(test_str, test_substr);
    int lib_result = strcmp(test_str, test_substr);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_equal_mid) {
    char *test_str = "12345";
    char *test_substr = "12345";
    s21_size_t n = 3;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_equal) {
    char *test_str = "12345";
    char *test_substr = "12345";
    s21_size_t n = 5;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
    } END_TEST

START_TEST(s21_strncmp_start_dif_plus) {
    char *test_str = "22345";
    char *test_substr = "12345";
    s21_size_t n = 7;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_start_dif_minus) {
    char *test_str = "12345";
    char *test_substr = "22345";
    s21_size_t n = 4;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_start_empty) {
    char *test_str = "22345";
    char *test_substr = "";
    s21_size_t n = 3;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_zero_n) {
    char *test_str = "22345";
    char *test_substr = "12345";
    s21_size_t n = 0;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_mid_dif) {
    char *test_str = "12345";
    char *test_substr = "13545";
    s21_size_t n = 4;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncmp_all_empty) {
    char *test_str = "";
    char *test_substr = "";
    s21_size_t n = 4;

    int s21_result = s21_strncmp(test_str, test_substr, n);
    int lib_result = strncmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memcmp_normal_equal) {
    char *test_str = "12345";
    char *test_substr = "12345";
    s21_size_t n = 7;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memcmp_zero_n) {
    char *test_str = "02345";
    char *test_substr = "12345";
    s21_size_t n = 0;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memcmp_normal_plus) {
    char *test_str = "12346";
    char *test_substr = "12345";
    s21_size_t n = 8;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memcmp_normal_minus) {
    char *test_str = "02346";
    char *test_substr = "04345";
    s21_size_t n = 2;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memcmp_all_empty) {
    char *test_str = "";
    char *test_substr = "";
    s21_size_t n = 2;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_trim_normal) {
    char *src = "-)(*123456789_0+#$!";
    char *trim_chars = "*()-_+#!$";

    char *s21_result = s21_trim(src, trim_chars);

    ck_assert_str_eq(s21_result, "123456789_0");
    free(s21_result);
} END_TEST

START_TEST(s21_trim_empty_src) {
    char *src = "";
    char *trim_chars = "*()-_+#!$";

    char *s21_result = s21_trim(src, trim_chars);

    ck_assert_ptr_eq(s21_result, s21_NULL);
    free(s21_result);
} END_TEST

START_TEST(s21_trim_empty_trim_chars) {
    char *src = "123456789";
    char *trim_chars = "";

    char *s21_result = s21_trim(src, trim_chars);

    ck_assert_str_eq(s21_result, "123456789");
    free(s21_result);
} END_TEST

START_TEST(s21_trim_all_empty) {
    char *src = "";
    char *trim_chars = "";

    char *s21_result = s21_trim(src, trim_chars);

    ck_assert_ptr_eq(s21_result, s21_NULL);
    free(s21_result);
} END_TEST


START_TEST(s21_memcmp_empty_str) {
    char *test_str = "";
    char *test_substr = "46545";
    s21_size_t n = 2;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memcmp_empty_substr) {
    char *test_str = "46426";
    char *test_substr = "";
    s21_size_t n = 2;

    int s21_result = s21_memcmp(test_str, test_substr, n);
    int lib_result = memcmp(test_str, test_substr, n);

    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

//  FREIDASH ****************************************

// s_21_memchr
START_TEST(s21_memchr_normal) {
    // Arrange
    char* str = "ABCDEFG";
    char sym = 'D';
    s21_size_t n = strlen(str);
    // Act
    char* s21_result = s21_memchr(str, sym, n);
    char* lib_result = memchr(str, sym, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memchr_empty_str) {
    // Arrange
    char* str = "";
    char sym = 'D';
    s21_size_t n = strlen(str);
    // Act
    char* s21_result = s21_memchr(str, sym, n);
    char* lib_result = memchr(str, sym, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memchr_empty_sym) {
    // Arrange
    char* str = "ABCDEFG";
    char sym = '\0';
    s21_size_t n = strlen(str);
    // Act
    char* s21_result = s21_memchr(str, sym, n);
    char* lib_result = memchr(str, sym, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memchr_n_zero) {
    // Arrange
    char* str = "ABCDEFG";
    char sym = 'D';
    s21_size_t n = 0;
    // Act
    char* s21_result = s21_memchr(str, sym, n);
    char* lib_result = memchr(str, sym, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_memchr_empty_str_sym) {
    // Arrange
    char* str = "";
    char sym = '\0';
    s21_size_t n = strlen(str);
    // Act
    char* s21_result = s21_memchr(str, sym, n);
    char* lib_result = memchr(str, sym, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

// s21_strcat
START_TEST(s21_strcat_normal) {
    // Arrange
    char str_1[20] = "hello";
    char *str_2 = "world";
    // Act
    char* s21_result = s21_strcat(str_1, str_2);
    char* lib_result = strcat(str_1, str_2);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcat_first_str_empty) {
    // Arrange
    char str_1[20];
    str_1[0] = '\0';
    char str_2[20];
    str_2[0] = '\0';
    char *str_3 = "world";
    // Act
    char* s21_result = s21_strcat(str_1, str_3);
    char* lib_result = strcat(str_2, str_3);
    // Assert
    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcat_second_str_empty) {
    // Arrange
    char str_1[20] = "hello";
    char *str_2 = "";
    // Act
    char* s21_result = s21_strcat(str_1, str_2);
    char* lib_result = strcat(str_1, str_2);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcat_both_str_empty) {
    // Arrange
    char str_1[20] = "";
    char *str_2 = "";
    // Act
    char* s21_result = s21_strcat(str_1, str_2);
    char* lib_result = strcat(str_1, str_2);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

// s21_strncat
START_TEST(s21_strncat_normal) {
    // Arrange
    char str_1[20] = "hello";
    char str_2[20] = "hello";
    char *str_3 = "world";
    s21_size_t n = 3;
    // Act
    char* s21_result = s21_strncat(str_1, str_3, n);
    char* lib_result = strncat(str_2, str_3, n);
    // Assert
    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncat_first_str_empty) {
    // Arrange
    char str_1[20] = "";
    char *str_2 = "world";
    s21_size_t n = 3;
    // Act
    char* s21_result = s21_strncat(str_1, str_2, n);
    char* lib_result = strncat(str_1, str_2, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncat_second_str_empty) {
    // Arrange
    char str_1[20] = "hello";
    char *str_2 = "";
    s21_size_t n = 3;
    // Act
    char* s21_result = s21_strncat(str_1, str_2, n);
    char* lib_result = strncat(str_1, str_2, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncat_both_str_empty) {
    // Arrange
    char str_1[20] = "";
    char *str_2 = "";
    s21_size_t n = 3;
    // Act
    char* s21_result = s21_strncat(str_1, str_2, n);
    char* lib_result = strncat(str_1, str_2, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncat_size_empty) {
    // Arrange
    char str_1[20] = "hello";
    char *str_2 = "world";
    s21_size_t n = 0;
    // Act
    char* s21_result = s21_strncat(str_1, str_2, n);
    char* lib_result = strncat(str_1, str_2, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncat_size_zero) {
    // Arrange
    char str_1[20] = "hello";
    char *str_2 = "world";
    s21_size_t n = 0;
    // Act
    char* s21_result = s21_strncat(str_1, str_2, n);
    char* lib_result = strncat(str_1, str_2, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strncat_all_empty) {
    // Arrange
    char str_1[20] = "";
    char *str_2 = "";
    s21_size_t n = 0;
    // Act
    char* s21_result = s21_strncat(str_1, str_2, n);
    char* lib_result = strncat(str_1, str_2, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

// s21_strchr
START_TEST(s21_strchr_normal) {
// Arrange
    char *str_1 = "hello";
    char n = 'h';
    // Act
    char* s21_result = s21_strchr(str_1, n);
    char* lib_result = strchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strchr_empty_str) {
    // Arrange
    char *str_1 = "";
    char n = 'h';
    // Act
    char* s21_result = s21_strchr(str_1, n);
    char* lib_result = strchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strchr_empty_sym) {
    // Arrange
    char *str_1 = "hello";
    char n = '\0';
    // Act
    char* s21_result = s21_strchr(str_1, n);
    char* lib_result = strchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strchr_both_empty) {
    // Arrange
    char *str_1 = "";
    char n = '\0';
    // Act
    char* s21_result = s21_strchr(str_1, n);
    char* lib_result = strchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

// s21_strcspn
START_TEST(s21_strcspn_normal) {
    char* str = "hello, world";
    char* keys = "wl";
    // Act
    s21_size_t s21_result = s21_strcspn(str, keys);
    s21_size_t lib_result = strcspn(str, keys);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcspn_empty_str) {
    char* str = "";
    char* keys = "wl";
    // Act
    s21_size_t s21_result = s21_strcspn(str, keys);
    s21_size_t lib_result = strcspn(str, keys);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcspn_empty_key) {
    char* str = "hello, world";
    char* keys = "";
    // Act
    s21_size_t s21_result = s21_strcspn(str, keys);
    s21_size_t lib_result = strcspn(str, keys);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strcspn_both_key) {
    char* str = "";
    char* keys = "";
    // Act
    s21_size_t s21_result = s21_strcspn(str, keys);
    s21_size_t lib_result = strcspn(str, keys);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

// s21_strrchr
START_TEST(s21_strrchr_normal) {
// Arrange
    char *str_1 = "hehllo";
    char n = 'h';
    // Act
    char* s21_result = s21_strrchr(str_1, n);
    char* lib_result = strrchr(str_1, n);
    // Assert
    ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strrchr_empty_str) {
    // Arrange
    char *str_1 = "";
    char n = 'h';
    // Act
    char* s21_result = s21_strrchr(str_1, n);
    char* lib_result = strrchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strrchr_empty_sym) {
    // Arrange
    char *str_1 = "hello";
    char n = '\0';
    // Act
    char* s21_result = s21_strrchr(str_1, n);
    char* lib_result = strrchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strrchr_both_empty) {
    // Arrange
    char *str_1 = "";
    char n = '\0';
    // Act
    char* s21_result = s21_strrchr(str_1, n);
    char* lib_result = strrchr(str_1, n);
    // Assert
    ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

// s21_strspn
START_TEST(s21_strspn_normal) {
    // Arrange
    char str_1[12] = "hello world";
    char *str_2 = "world";
    // Act
    int s21_result = s21_strspn(str_1, str_2);
    int lib_result = strspn(str_1, str_2);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strspn_first_str_empty) {
    // Arrange
    char str_1[0] = "";
    char *str_2 = "world";
    // Act
    int s21_result = s21_strspn(str_1, str_2);
    int lib_result = strspn(str_1, str_2);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strspn_second_str_empty) {
    // Arrange
    char str_1[12] = "hello world";
    char *str_2 = "";
    // Act
    int s21_result = s21_strspn(str_1, str_2);
    int lib_result = strspn(str_1, str_2);
    // Assert
    ck_assert_int_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strspn_str2_not_in_str1) {
        // Arrange
        char str_1[12] = "hello world";
        char *str_2 = "mac";
        // Act
        int s21_result = s21_strspn(str_1, str_2);
        int lib_result = strspn(str_1, str_2);
        // Assert
        ck_assert_int_eq(s21_result, lib_result);
    } END_TEST

START_TEST(s21_strspn_both_empty) {
        // Arrange
        char str_1[0] = "";
        char *str_2 = "";
        // Act
        int s21_result = s21_strspn(str_1, str_2);
        int lib_result = strspn(str_1, str_2);
        // Assert
        ck_assert_int_eq(s21_result, lib_result);
    } END_TEST

//  s21_to_lower
START_TEST(s21_to_lower_normal) {
        // Arrange
    char* test_str0 = "HELLO WORLD";
    char* test_str1 = "H1E2L3L4O5";
        // Act
    char* func_result0 = s21_to_lower(test_str0);
    char* func_result1 = s21_to_lower(test_str1);
        // Assert
    ck_assert_str_eq(func_result0, "hello world");
    ck_assert_str_eq(func_result1, "h1e2l3l4o5");
    free(func_result0);
    free(func_result1);
} END_TEST

START_TEST(s21_to_lower_with_sign) {
        // Arrange
    char* test_str = "H!E1L/L&O.";
        // Act
    char* func_result = s21_to_lower(test_str);
        // Assert
    ck_assert_str_eq(func_result, "h!e1l/l&o.");
    free(func_result);
} END_TEST

START_TEST(s21_to_lower_with_lower) {
        // Arrange
    char* test_str = "hello";
        // Act
    char* func_result = s21_to_lower(test_str);
        // Assert
    ck_assert_str_eq(func_result, test_str);
    free(func_result);
} END_TEST

START_TEST(s21_to_lower_empty_string) {
    // Arrange
    char* test_str0 = "";
    // Act
    char* func_result = s21_to_lower(test_str0);
    // Assert
    ck_assert_ptr_eq(func_result, s21_NULL);
    free(func_result);
} END_TEST




Suite* s21_string_suite() {
    Suite* s;
    TCase* tc_insert, *tc_trim, * tc_strerror, * tc_sprintf,
        * tc_strncpy, *tc_strcpy, * tc_memmove, *tc_memcpy,
        * tc_to_upper, * tc_strtok, * tc_strpbrk, * tc_memset,
        * tc_strlen, *tc_strstr, *tc_strcmp, *tc_strncmp, *tc_memcmp,
        * tc_memchr, * tc_strcat, * tc_strncat, * tc_strchr, * tc_strcspn,
        * tc_strrchr, * tc_strspn, * tc_to_lower;

    s = suite_create("s21_string");

    tc_insert = tcase_create("s21_insert");
    tcase_add_test(tc_insert, s21_insert_normal);
    tcase_add_test(tc_insert, s21_insert_empty_src);
    tcase_add_test(tc_insert, s21_insert_empty_str);
    tcase_add_test(tc_insert, s21_insert_invalid_index);
    suite_add_tcase(s, tc_insert);

    tc_memmove = tcase_create("s21_memmove");
    tcase_add_test(tc_memmove, s21_memmove_normal);
    tcase_add_test(tc_memmove, s21_memmove_with_index);
    tcase_add_test(tc_memmove, s21_memmove_with_index_both);
    tcase_add_test(tc_memmove, s21_memmove_out);
    tcase_add_test(tc_memmove, s21_memmove_dest_short);
    suite_add_tcase(s, tc_memmove);

    tc_memcpy = tcase_create("s21_memcpy");
    tcase_add_test(tc_memcpy, s21_memcpy_normal);
    tcase_add_test(tc_memcpy, s21_memcpy_out);
    tcase_add_test(tc_memcpy, s21_memcpy_empty_dest);
    tcase_add_test(tc_memcpy, s21_memcpy_empty_src);
    suite_add_tcase(s, tc_memcpy);

    tc_strcpy = tcase_create("s21_strcpy");
    tcase_add_test(tc_strcpy, s21_strcpy_normal);
    tcase_add_test(tc_strcpy, s21_strcpy_out);
    suite_add_tcase(s, tc_strcpy);

    tc_strncpy = tcase_create("s21_strncpy");
    tcase_add_test(tc_strncpy, s21_strncpy_normal);
    tcase_add_test(tc_strncpy, s21_strncpy_out);
    suite_add_tcase(s, tc_strncpy);

    tc_to_upper = tcase_create("s21_to_upper");
    tcase_add_test(tc_to_upper, s21_to_upper_normal);
    tcase_add_test(tc_to_upper, s21_to_upper_whith_sign);
    tcase_add_test(tc_to_upper, s21_to_upper_whith_upper);
    tcase_add_test(tc_to_upper, s21_to_upper_empty_string);
    suite_add_tcase(s, tc_to_upper);

    tc_strtok = tcase_create("s21_strtok");
    tcase_add_test(tc_strtok, s21_strtok_normal);
    tcase_add_test(tc_strtok, s21_strtok_no_delimetr);
    tcase_add_test(tc_strtok, s21_strtok_empty);
    suite_add_tcase(s, tc_strtok);

    tc_strpbrk = tcase_create("s21_strpbrk");
    tcase_add_test(tc_strpbrk, s21_strpbrk_normal);
    tcase_add_test(tc_strpbrk, s21_strpbrk_no_symb);
    tcase_add_test(tc_strpbrk, s21_strpbrk_empty_symb);
    tcase_add_test(tc_strpbrk, s21_strpbrk_empty_str);
    suite_add_tcase(s, tc_strpbrk);

    tc_memset = tcase_create("s21_memset");
    tcase_add_test(tc_memset, s21_memset_normal);
    tcase_add_test(tc_memset, s21_memset_null);
    tcase_add_test(tc_memset, s21_memset_sign);
    suite_add_tcase(s, tc_memset);

    tc_strerror = tcase_create("s21_strerror");
    tcase_add_test(tc_strerror, s21_strerror_normal);
    suite_add_tcase(s, tc_strerror);

    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_d);
    tcase_add_test(tc_sprintf, s21_sprintf_u);
    tcase_add_test(tc_sprintf, s21_sprintf_cs);
    tcase_add_test(tc_sprintf, s21_sprintf_f);
    tcase_add_test(tc_sprintf, s21_sprintf_eE);
    tcase_add_test(tc_sprintf, s21_sprintf_xX);
    tcase_add_test(tc_sprintf, s21_sprintf_o);
    tcase_add_test(tc_sprintf, s21_sprintf_i);
    tcase_add_test(tc_sprintf, s21_sprintf_p);
    tcase_add_test(tc_sprintf, s21_sprintf_n);
    tcase_add_test(tc_sprintf, s21_sprintf_s);
    tcase_add_test(tc_sprintf, s21_sprintf_h);
    tcase_add_test(tc_sprintf, s21_sprintf_l);
    tcase_add_test(tc_sprintf, s21_sprintf_L);
    tcase_add_test(tc_sprintf, s21_sprintf_gG);
    tcase_add_test(tc_sprintf, s21_sprintf_star);
    tcase_add_test(tc_sprintf, s21_sprintf_empty);
    tcase_add_test(tc_sprintf, s21_sprintf_diu_whith_str);
    tcase_add_test(tc_sprintf, s21_sprintf_f_with_str);
    suite_add_tcase(s, tc_sprintf);


    tc_strlen = tcase_create("s21_strlen");
    tcase_add_test(tc_strlen, s21_strlen_normal);
    tcase_add_test(tc_strlen, s21_strlen_empty);
    suite_add_tcase(s, tc_strlen);

    tc_strstr = tcase_create("s21_strstr");
    tcase_add_test(tc_strstr, s21_strstr_normal);
    tcase_add_test(tc_strstr, s21_strstr_SF);
    tcase_add_test(tc_strstr, s21_strstr_empty);
    tcase_add_test(tc_strstr, s21_strstr_all_empty);
    suite_add_tcase(s, tc_strstr);

    tc_strcmp = tcase_create("s21_strcmp");
    tcase_add_test(tc_strcmp, s21_strcmp_all_empty);
    tcase_add_test(tc_strcmp, s21_strcmp_empty);
    tcase_add_test(tc_strcmp, s21_strcmp_equal);
    tcase_add_test(tc_strcmp, s21_strcmp_midle_dif_minus);
    tcase_add_test(tc_strcmp, s21_strcmp_midle_dif_plus);
    tcase_add_test(tc_strcmp, s21_strcmp_normal_minus);
    tcase_add_test(tc_strcmp, s21_strcmp_normal_plus);
    suite_add_tcase(s, tc_strcmp);

    tc_strncmp = tcase_create("s21_strncmp");
    tcase_add_test(tc_strncmp, s21_strncmp_all_empty);
    tcase_add_test(tc_strncmp, s21_strncmp_start_empty);
    tcase_add_test(tc_strncmp, s21_strncmp_start_dif_minus);
    tcase_add_test(tc_strncmp, s21_strncmp_start_dif_plus);
    tcase_add_test(tc_strncmp, s21_strncmp_mid_dif);
    tcase_add_test(tc_strncmp, s21_strncmp_equal);
    tcase_add_test(tc_strncmp, s21_strncmp_equal_mid);
    tcase_add_test(tc_strncmp, s21_strncmp_zero_n);
    suite_add_tcase(s, tc_strncmp);


    tc_memcmp = tcase_create("s21_memcmp");
    tcase_add_test(tc_memcmp, s21_memcmp_normal_equal);
    tcase_add_test(tc_memcmp, s21_memcmp_normal_minus);
    tcase_add_test(tc_memcmp, s21_memcmp_normal_plus);
    tcase_add_test(tc_memcmp, s21_memcmp_zero_n);
    tcase_add_test(tc_memcmp, s21_memcmp_all_empty);
    tcase_add_test(tc_memcmp, s21_memcmp_empty_str);
    tcase_add_test(tc_memcmp, s21_memcmp_empty_substr);
    suite_add_tcase(s, tc_memcmp);

    tc_memchr = tcase_create("s21_memchr");
    tcase_add_test(tc_memchr, s21_memchr_normal);
    tcase_add_test(tc_memchr, s21_memchr_empty_str);
    tcase_add_test(tc_memchr, s21_memchr_empty_sym);
    tcase_add_test(tc_memchr, s21_memchr_n_zero);
    tcase_add_test(tc_memchr, s21_memchr_empty_str_sym);
    suite_add_tcase(s, tc_memchr);

    tc_strcat = tcase_create("s21_strcat");
    tcase_add_test(tc_strcat, s21_strcat_normal);
    tcase_add_test(tc_strcat, s21_strcat_first_str_empty);
    tcase_add_test(tc_strcat, s21_strcat_second_str_empty);
    tcase_add_test(tc_strcat, s21_strcat_both_str_empty);
    suite_add_tcase(s, tc_strcat);

    tc_strncat = tcase_create("s21_strncat");
    tcase_add_test(tc_strncat, s21_strncat_normal);
    tcase_add_test(tc_strncat, s21_strncat_first_str_empty);
    tcase_add_test(tc_strncat, s21_strncat_second_str_empty);
    tcase_add_test(tc_strncat, s21_strncat_both_str_empty);
    tcase_add_test(tc_strncat, s21_strncat_size_empty);
    tcase_add_test(tc_strncat, s21_strncat_size_zero);
    tcase_add_test(tc_strncat, s21_strncat_all_empty);
    suite_add_tcase(s, tc_strncat);

    tc_strchr = tcase_create("s21_strchr");
    tcase_add_test(tc_strchr, s21_strchr_normal);
    tcase_add_test(tc_strchr, s21_strchr_empty_str);
    tcase_add_test(tc_strchr, s21_strchr_empty_sym);
    tcase_add_test(tc_strchr, s21_strchr_both_empty);
    suite_add_tcase(s, tc_strchr);

    tc_strcspn = tcase_create("s21_strcspn");
    tcase_add_test(tc_strcspn, s21_strcspn_normal);
    tcase_add_test(tc_strcspn, s21_strcspn_empty_str);
    tcase_add_test(tc_strcspn, s21_strcspn_empty_key);
    tcase_add_test(tc_strcspn, s21_strcspn_both_key);
    suite_add_tcase(s, tc_strcspn);

    tc_strrchr = tcase_create("s21_strrchr");
    tcase_add_test(tc_strrchr, s21_strrchr_normal);
    tcase_add_test(tc_strrchr, s21_strrchr_empty_str);
    tcase_add_test(tc_strrchr, s21_strrchr_empty_sym);
    tcase_add_test(tc_strrchr, s21_strrchr_both_empty);
    suite_add_tcase(s, tc_strrchr);

    tc_strspn = tcase_create("s21_strspn");
    tcase_add_test(tc_strspn, s21_strspn_normal);
    tcase_add_test(tc_strspn, s21_strspn_first_str_empty);
    tcase_add_test(tc_strspn, s21_strspn_second_str_empty);
    tcase_add_test(tc_strspn, s21_strspn_str2_not_in_str1);
    tcase_add_test(tc_strspn, s21_strspn_both_empty);
    suite_add_tcase(s, tc_strspn);

    tc_to_lower = tcase_create("s21_to_lower");
    tcase_add_test(tc_to_lower, s21_to_lower_normal);
    tcase_add_test(tc_to_lower, s21_to_lower_with_sign);
    tcase_add_test(tc_to_lower, s21_to_lower_with_lower);
    tcase_add_test(tc_to_lower, s21_to_lower_empty_string);
    suite_add_tcase(s, tc_to_lower);


    tc_trim = tcase_create("s21_trim");
    tcase_add_test(tc_trim, s21_trim_normal);
    tcase_add_test(tc_trim, s21_trim_empty_src);
    tcase_add_test(tc_trim, s21_trim_empty_trim_chars);
    tcase_add_test(tc_trim, s21_trim_all_empty);
    suite_add_tcase(s, tc_trim);

  return s;
}

int main() {
    int no_failed = 0;
    Suite* s;
    SRunner* runner;

    s = s21_string_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
