#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define size_i 25
#define size_j 80

void game_over();
void presentation_area(char a[size_i][size_j]);
void input(int a[size_i][size_j]);
void copy(int a[size_i][size_j], int b[size_i][size_j]);
void cell_birth_processing(int old[size_i][size_j], int new[size_i][size_j]);
void translate(int a[size_i][size_j], char b[size_i][size_j]);
int compare(int a[size_i][size_j], int b[size_i][size_j]);

int main() {
  int a[size_i][size_j];
  int buffer[size_i][size_j];
  int flag = 1;
  char show[size_i][size_j];
  char scan = 'r';
  int speed = 1;

  input(a);
  copy(a, buffer);
  if (freopen("/dev/tty", "r", stdin) == NULL) {
    fprintf(stderr, "Unable to redirect stdin from file\n");
    exit(1);
  }
  initscr();
  nodelay(stdscr, TRUE);
  noecho();

  while (flag) {
    clear();
    translate(a, show);
    presentation_area(show);
    refresh();
    cell_birth_processing(a, buffer);
    if (compare(buffer, a) == 0) {
      flag = 0;
    }
    copy(buffer, a);
    halfdelay(speed);
    scan = getch();
    if (scan == 'q') {
      flag = 0;
    }
    if (scan == 'z') {
      speed = speed + 1;
    }
    if (scan == 'a') {
      speed = speed - 1;
    }
  }
  endwin();
  if (scan != 'q') {
    game_over();
  }
  return 0;
}

void input(int a[size_i][size_j]) {
  for (int i = 0; i < size_i; i++) {
    for (int j = 0; j < size_j; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}
void presentation_area(char a[size_i][size_j]) {
  for (int i = 0; i < size_i; i++) {
    for (int j = 0; j < size_j; j++) {
      printw("%c", a[i][j]);
      if (j != size_j - 1) {
        printw(" ");
      } else {
        printw("\n");
      }
    }
  }
}
void copy(int a[size_i][size_j], int b[size_i][size_j]) {
  for (int i = 0; i < size_i; i++) {
    for (int j = 0; j < size_j; j++) {
      b[i][j] = a[i][j];
    }
  }
}

void cell_birth_processing(int old[size_i][size_j], int new[size_i][size_j]) {
  int number;
  for (int i = 0; i < size_i; i++) {
    for (int j = 0; j < size_j; j++) {
      number = 0;
      for (int y = i - 1; y <= i + 1; y++) {
        for (int x = j - 1; x <= j + 1; x++) {
          if (!(x == j && y == i)) {
            if (old[(size_i + y) % size_i][(size_j + x) % size_j] == 1) {
              number++;
            }
          }
        }
      }
      if (number > 3) {
        new[i][j] = 0;
      }
      if (number == 3) {
        new[i][j] = 1;
      }
      if (number < 2) {
        new[i][j] = 0;
      }
    }
  }
}

void translate(int a[size_i][size_j], char b[size_i][size_j]) {
  for (int i = 0; i < size_i; i++) {
    for (int j = 0; j < size_j; j++) {
      if (a[i][j] == 1) {
        b[i][j] = 'o';
      } else {
        b[i][j] = '.';
      }
    }
  }
}

int compare(int a[size_i][size_j], int b[size_i][size_j]) {
  int flag = 0;
  for (int i = 0; i < size_i; i++) {
    for (int j = 0; j < size_j; j++) {
      if (a[i][j] != b[i][j]) {
        flag = 1;
      }
    }
  }
  return flag;
}

void game_over() {
  printf("                  ---------------------\n");
  printf("                  |                   |\n");
  printf("                  |                   |\n");
  printf("                  |     GAME OVER     |\n");
  printf("                  |                   |\n");
  printf("                  |                   |\n");
  printf("                  ---------------------\n");
}
