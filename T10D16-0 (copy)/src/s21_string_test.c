
#include "s21_string.h"
#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();

int main() {
#ifdef Strlen_tests
  s21_strlen_test();
#endif
#ifdef Strcmp_tests
  s21_strcmp_test();
#endif
#ifdef Strcpy_tests
  s21_strcpy_test();
#endif
#ifdef Strcat_tests
  s21_strcat_test();
#endif
#ifdef Strchr_tests
  s21_strchr_test();
#endif
  return 0;
}

void s21_strlen_test() {
  printf("abcd\n");
  printf("%ld\n", s21_strlen("abcd"));

  if (s21_strlen("abcd") == 4) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  printf("\n");
  printf("%ld\n", s21_strlen(""));
  if (s21_strlen("") == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  printf("Abcd\\0dfdf\n");
  printf("%ld\n", s21_strlen("Abcd\0dfdf"));

  if (s21_strlen("Abcd\0dfdf") == 4) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void s21_strcmp_test() {
  char *a1 = "ABCDE";
  char *a2 = "ABCDE";

  char *b1 = "ABCDE";
  char *b2 = "ABCD";

  char *c1 = "";
  char *c2 = "ABCDE";

  char *d1 = "hhha";
  char *d2 = "hhhh";

  printf("ABCDE\n");
  printf("ABCDE\n");
  printf("0\n");
  if (s21_strcmp(a1, a2) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  printf("ABCDE\n");
  printf("ABCD\n");
  printf("%d\n", s21_strcmp(b1, b2));
  if (s21_strcmp(b1, b2) > 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  printf("\n");
  printf("ABCDE\n");
  printf("%d\n", s21_strcmp(c1, c2));
  if (s21_strcmp(c1, c2) < 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  printf("hhha\n");
  printf("hhhh\n");
  printf("%d\n", s21_strcmp(d1, d2));
  if (s21_strcmp(d1, d2) < 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void s21_strcpy_test() {
  char source1[] = "hello world";
  char destination1[25];
  printf("%s\n", source1);
  printf("%s\n", s21_strcpy(destination1, source1));
  if (s21_strcmp(destination1, source1) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  char source2[] = "hello\0world";
  char destination2[25];
  printf("hello\\0world\n");
  printf("%s\n", s21_strcpy(destination2, source2));
  if (s21_strcmp(destination2, source2) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  char source3[] = "hello";
  printf("%s\n", source3);
  printf("NULL\n");
  if (s21_strcpy(NULL, source3) == NULL) {
    printf("NULL\n");
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void s21_strcat_test() {
  char source1[] = "world";
  char destination1[25] = "hello ";
  printf("hello \n");
  printf("world\n");
  s21_strcat(destination1, source1);
  printf("%s\n", destination1);
  if (s21_strcmp(destination1, "hello world") == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  char source2[] = "world";
  char destination2[25] = "hello \0 all ";
  printf("hello \\0 all \n");
  printf("world\n");
  s21_strcat(destination2, source2);
  printf("%s\n", destination2);
  if (s21_strcmp(destination2, "hello world") == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  char source3[] = "world";
  char destination3[25] = "";
  printf("\n");
  printf("world\n");
  s21_strcat(destination3, source3);
  printf("%s\n", destination3);
  if (s21_strcmp(destination3, "world") == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void s21_strchr_test() {
  int ch1 = '5';
  char source1[] = "1234578";
  char *n = s21_strchr(source1, ch1);
  printf("%d\n", 5);
  printf("%s\n", source1);

  if (s21_strcmp(n, "578") == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  int ch2 = '5';
  char source2[] = "123478";
  printf("%d\n", 5);
  printf("%s\n", source2);
  if (s21_strchr(source2, ch2) == NULL) {
    printf("NULL\n");
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}
