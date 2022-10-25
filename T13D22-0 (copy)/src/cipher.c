#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENG 26

void copy(FILE *fp1, FILE *fp2);
void cezar_code(char *filename, int n);
void cezar_code_files(int n);

int main(void) {
  char filename[80];
  char str_output[256];
  char str_write[256];
  int flag = 1;
  int flag_1 = 0;
  int regim;
  FILE *fp;

#ifdef log
  FILE *log_file;
  log_file = log_init("logs.txt");
  enum log_level level;
#endif

  while (flag) {
    if (scanf("%d", &regim) != 0) {
      if (regim == -1) {
        flag = 0;
      }
    }
    int a = 0;
    if (flag && regim == 1) {
      scanf("%s", filename);
      fp = fopen(filename, "r");
      if (fp == NULL) {
        printf("n/a\n");
        flag_1 = 0;
      } else {
        flag_1 = 1;
        while (fgets(str_output, 256, fp) != NULL) {
          printf("%s", str_output);
          a = 1;
        }
        if (a == 0) {
          printf("n/a\n");
        } else {
          printf("\n");
        }
        fclose(fp);
      }
    }
    if (flag && regim == 2) {
      if (flag_1 == 0) {
        printf("n/a\n");
      }
      if (flag_1 == 1) {
        fp = fopen(filename, "a");
        scanf("%s", str_write);
        fputs(str_write, fp);

#ifdef log
        level = info;
        logcat(log_file, "в файл дозаписана строка", level);
#endif

        fputs("\n", fp);
        fclose(fp);
        if ((fp = fopen(filename, "r")) == NULL) {
          printf("n/a\n");
        }
        while (fgets(str_output, 256, fp) != NULL) {
          printf("%s", str_output);
        }
      }
      flag_1 = 0;
    }
    if (flag && regim == 3) {
      int n;
      printf("enter the shift value for the Caesar cipher:\n");
      scanf("%d", &n);
      system("rm -rf ai_modules/*.h");
      system("find ai_modules/*.c > files_s.txt");
      cezar_code_files(n);
      system("rm -rf output.txt");
    }
  }
#ifdef log
  level = info;
  logcat(log_file, "программа успешно завершена", level);
  log_close(log_file);
#endif
  return 0;
}

void cezar_code_files(int n) {
  char filename[100];
  FILE *fp3;
  fp3 = fopen("files_s.txt", "r");
  while (fgets(filename, 256, fp3) != NULL) {
    filename[strlen(filename) - 1] = '\0';
    cezar_code(filename, n);
  }
  fclose(fp3);
}

void copy(FILE *fp1, FILE *fp2) {
  char str_write[256];
  while (fgets(str_write, 256, fp1) != NULL) {
    fputs(str_write, fp2);
  }
}

void cezar_code(char *filename, int n) {
  FILE *fp1, *fp2;
  if ((fp1 = fopen(filename, "r")) == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  fp2 = fopen("output.txt", "w");
  int flag;
  char c;
  c = getc(fp1);
  while (!feof(fp1)) {
    flag = 0;
    if (c >= 'A' && c <= 'Z') {
      c = c + (n % ENG);
      if (c > 'Z')
        c = 'A' + (c - 'Z') - 1;
      fprintf(fp2, "%c", c);
      flag = 1;
    }
    if (c >= 'a' && c <= 'z') {
      c = c + (n % ENG);
      if (c > 'z')
        c = 'a' + (c - 'z') - 1;
      fprintf(fp2, "%c", c);
      flag = 1;
    }
    if (!flag)
      fprintf(fp2, "%c", c);
    c = getc(fp1);
  }
  fclose(fp1);
  fclose(fp2);
  fp1 = fopen(filename, "w");
  fp2 = fopen("output.txt", "r");
  copy(fp2, fp1);
  fclose(fp1);
  fclose(fp2);
}
