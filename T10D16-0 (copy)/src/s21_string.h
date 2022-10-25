#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>

size_t s21_strlen(const char *data);
int s21_strcmp(const char *first_str, const char *second_str);
char *s21_strcpy(char *first_str, const char *second_str);
char *s21_strcat(char *restrict, const char *restrict);
char *s21_strchr(const char *s, int c);
#endif  // SRC_S21_STRING_H_
