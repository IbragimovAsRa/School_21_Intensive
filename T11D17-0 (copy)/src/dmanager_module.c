#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void bubl_sort(struct door *doors, int n);
void close(struct door *doors, int n);

int main() {
  struct door doors[DOORS_COUNT];

  initialize_doors(doors);
  bubl_sort(doors, DOORS_COUNT);
  close(doors, DOORS_COUNT);
  for (int i = 0; i < DOORS_COUNT; i++) {
    printf("%d, %d\n", doors[i].id, doors[i].status);
  }
  return 0;
}

void initialize_doors(struct door *doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}

void bubl_sort(struct door *doors, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (doors[j].id > doors[j + 1].id) {
        struct door tmp = doors[j];
        doors[j] = doors[j + 1];
        doors[j + 1] = tmp;
      }
    }
  }
}

void close(struct door *doors, int n) {
  for (int i = 0; i < n; i++) {
    doors[i].status = 0;
  }
}
