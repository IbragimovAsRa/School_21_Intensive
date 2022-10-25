#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_

#include <stdio.h>
#include <stdlib.h>

struct door {
    int id;
    int status;
};

struct node {
struct door data;
struct node *next;
};

#endif  // SRC_DOOR_STRUCT_H_
