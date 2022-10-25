
#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "door_struct.h"

struct node* add_door(struct node* elem, struct door* door);
struct node* init(struct door* door);
struct node* remove_door(struct node* elem, struct node* root);
struct node* find_door(int door_id, struct node* root);
void destroy(struct node* root);

#endif  // SRC_LIST_H_
