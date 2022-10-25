#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t i;
  for (i = 0; *(str + i) != 0; i++) {}
  return i;
}
int s21_strcmp(const char *first_str, const char *second_str) {
  {
    while (*first_str) {
      if (*first_str != *second_str) {
        break;
      }
      first_str++;
      second_str++;
    }
    return *(const unsigned char *)first_str -
           *(const unsigned char *)second_str;
  }
}
char *s21_strcpy(char *first_str, const char *second_str) {
  if (first_str == NULL) {
    return NULL;
  }
  char *ptr = first_str;
  while (*second_str != '\0') {
    *first_str = *second_str;
    first_str++;
    second_str++;
  }
  *first_str = '\0';
  return ptr;
}

char *s21_strcat(char *destin, const char *source) {
  char *ptr = destin + s21_strlen(destin);
  while (*source != '\0') {
    *ptr++ = *source++;
  }
  *ptr = '\0';
  return destin;
}

char *s21_strchr(const char *s, int c) {
  while (*s != (char)c) {
    if (!*s++) {
      return NULL;
    }
  }
  return (char *)s;
}
