#include "logger.h"

FILE *log_init(char *filename) {
  FILE *fp;
  fp = fopen(filename, "a+");
  return fp;
}

int logcat(FILE *log_file, char *message, enum log_level level) {
  long int ttime;
  ttime = time(NULL);

  switch (level) {
  case debug:
    fprintf(log_file, "DEBUG %s - %s", ctime(&ttime), message);
    fprintf(log_file, "\n");
    break;
  case info:
    fprintf(log_file, "INFO %s - %s", ctime(&ttime), message);
    fprintf(log_file, "\n");
    break;
  case warning:
    fprintf(log_file, "WARNING %s - %s", ctime(&ttime), message);
    fprintf(log_file, "\n");
    break;
  case error:
    fprintf(log_file, "ERROR %s - %s", ctime(&ttime), message);
    fprintf(log_file, "\n");
    break;
  default:
    break;
  }
  return 0;
}

int log_close(FILE *log_file) {
  fclose(log_file);
  return 0;
}
