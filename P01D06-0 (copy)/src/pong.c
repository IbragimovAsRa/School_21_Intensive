#include <math.h>
#include <stdio.h>

void desplay_frame(int ball_x, int ball_y, int delt_y_le, int delt_y_ri,
                   int pad_first_y, int pad_second_y);
void desplay_win(int pl);

int main() {
  int pad_first_y = 13;
  int pad_second_y = 13;

  int ball_x = 20;
  int ball_y = 13;

  int ball_del_x = 1;
  int ball_del_y = -1;

  int delt_y_le = 0;
  int delt_y_ri = 0;

  char button;

  int tablo_ri = 0;
  int tablo_le = 0;

  while (scanf("%c", &button) != 0) {
    printf("\033[0d\033[2J");
    if (button == 'q') {
      break;
    }

    printf("ball X: %d;\n", ball_x);
    printf("ball Y: %d;\n", ball_y);

    printf("                                      TABLO\n\n\n");

    if (ball_x > 79) {
      printf("            first player : %d                       second "
             "player: %d\n",
             tablo_le++, tablo_ri);
      ball_y = pad_first_y + delt_y_le;
      ball_x = 7;
    } else if (ball_x < 1) {
      printf("            first player : %d                       second "
             "player: %d\n",
             tablo_le, tablo_ri++);
      ball_y = pad_second_y + delt_y_ri;
      ball_x = 71;
    } else {
      printf("            first player : %d                       second "
             "player: %d\n",
             tablo_le, tablo_ri);
    }

    if (button == 'A' || button == 'Z' || button == 'K' || button == 'M' ||
        button == ' ') {
      // удары о правую ракетку
      if (ball_x == 74 && (ball_y == pad_second_y + delt_y_ri ||
                           ball_y == pad_second_y + delt_y_ri + 1 ||
                           ball_y == pad_second_y + delt_y_ri - 1)) {
        ball_del_x = ball_del_x * (-1);
      }

      if (ball_x == 4 && (ball_y == pad_first_y + delt_y_le ||
                          ball_y == pad_first_y + delt_y_le + 1 ||
                          ball_y == pad_first_y + delt_y_le - 1)) {
        ball_del_x = ball_del_x * (-1);
      }

      if (ball_y == 1 || ball_y == 23) {
        ball_del_y = ball_del_y * (-1);
      }
      ball_x += ball_del_x;
      ball_y += ball_del_y;

      if (button == 'A' && (pad_first_y + delt_y_le != 2)) {
        delt_y_le--;
      }
      if (button == 'Z' && (pad_first_y + delt_y_le != 22)) {
        delt_y_le++;
      }

      if (button == 'K' && (pad_second_y + delt_y_ri != 2)) {
        delt_y_ri--;
      }
      if (button == 'M' && (pad_second_y + delt_y_ri != 22)) {
        delt_y_ri++;
      }
    }
    desplay_frame(ball_x, ball_y, delt_y_le, delt_y_ri, pad_first_y,
                  pad_second_y);
    if (tablo_ri == 21) {
      desplay_win(2);
      break;
    }
    if (tablo_le == 21) {
      desplay_win(1);
      break;
    }
  }
  return 0;
}

void desplay_frame(int ball_x, int ball_y, int delt_y_le, int delt_y_ri,
                   int pad_first_y, int pad_second_y) {
  for (int y = 0; y < 25; y++) {
    for (int x = 0; x < 80; x++) {
      if (x == ball_x && y == ball_y) {
        printf("o");
      } else if (y == 0 || y == 24) {
        printf("-");
      } else if (x == 40) {
        printf("|");
      } else if (x == 0 || x == 79) {
        printf(".");
      } else if (x == 3 && (y == pad_first_y + delt_y_le ||
                            y == pad_first_y + delt_y_le + 1 ||
                            y == pad_first_y + delt_y_le - 1)) {
        printf("]");

      } else if (x == 76 && (y == pad_second_y + delt_y_ri ||
                             y == pad_second_y + delt_y_ri + 1 ||
                             y == pad_second_y + delt_y_ri - 1)) {
        printf("[");

      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void desplay_win(int pl) {
  if (pl == 2) {
    printf("___________________________________________________\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|             !!! SECOND PLAYER WINS !!!           |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|__________________________________________________|\n");
  } else if (pl == 1) {
    printf("___________________________________________________\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|             !!! FIRST PLAYER WINS !!!            |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|__________________________________________________|\n");
  }
}
