#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"
#include "list.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void bubl_sort(struct door *doors, int n);
void close(struct door *doors, int n);
struct node *create_list(struct door *doors, int N);
void print_list(struct node *p_begin);
int s21_strcmp(const char *first_str, const char *second_str);
int main() {
  struct door doors[DOORS_COUNT];
  initialize_doors(doors);
  bubl_sort(doors, DOORS_COUNT);
  close(doors, DOORS_COUNT);
  printf("____TEST_REMOVE_DOOR____\n\n");
  struct node *p_begin = create_list(doors, DOORS_COUNT);
  printf("INPUT:\n");
  print_list(p_begin);
  struct node *del_val =
      find_door(5, p_begin);
  del_val = remove_door(del_val, p_begin);
  printf("\n");
  printf("OUTPUT:\n");
  print_list(p_begin);
  printf("\n");
  if (find_door(5, p_begin) == NULL) {
    printf("SUCCESS");
  } else {
    printf("FAIL");
  }
  printf("\n");
  printf("INPUT:\n");
  print_list(p_begin);
  del_val = find_door(8, p_begin);
  del_val = remove_door(del_val, p_begin);
  printf("\n");
  printf("OUTPUT:\n");
  print_list(p_begin);
  printf("\n");
  if (find_door(8, p_begin) == NULL) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  printf("INPUT:\n");
  print_list(p_begin);
  del_val = find_door(14, p_begin);
  del_val = remove_door(del_val, p_begin);
  printf("\n");
  printf("OUTPUT:\n");
  print_list(p_begin);
  printf("\n");
  if (find_door(14, p_begin) == NULL) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  printf("\n");
  destroy(p_begin);
  printf("____TEST_ADD_DOOR____\n\n");
  struct node *p_begin2 = create_list(doors, DOORS_COUNT);
  struct node *elem_val;
  printf("\n");
  printf("INPUT:\n");
  print_list(p_begin2);
  elem_val = find_door(8, p_begin2);
  elem_val = add_door(elem_val, &doors[8]);
  printf("\n");
  printf("OUTPUT:\n");
  print_list(p_begin2);
  printf("\n");
  printf("SUCCESS\n");
  printf("INPUT:\n");
  print_list(p_begin2);
  elem_val = find_door(14, p_begin2);
  elem_val = add_door(elem_val, &doors[14]);
  printf("\n");
  printf("OUTPUT:\n");
  print_list(p_begin2);
  printf("\n");
  printf("SUCCESS\n");
  printf("INPUT:\n");
  print_list(p_begin2);
  elem_val = find_door(0, p_begin2);
  elem_val = add_door(elem_val, &doors[0]);
  printf("\n");
  printf("OUTPUT:\n");
  print_list(p_begin2);
  printf("\n");
  printf("SUCCESS\n");
  printf("\n");
  destroy(p_begin2);
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

struct node *create_list(struct door *doors, int N) {
  struct node *p_begin = NULL;
  struct node *p = NULL;
  p_begin = (struct node *)malloc(sizeof(struct node));
  p = p_begin;
  p->next = NULL;
  p->data = doors[0];
  for (int k = 1; k < N; k++) {
    p->next = (struct node *)malloc(sizeof(struct node));
    p = p->next;
    p->next = NULL;
    p->data = doors[k];
  }
  return p_begin;
}

void print_list(struct node *p_begin) {
  struct node *p = p_begin;
  while (p != NULL) {
    printf("%d ", p->data.id);
    p = p->next;
  }
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
