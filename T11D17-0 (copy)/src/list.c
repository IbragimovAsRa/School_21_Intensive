#include "list.h"
#include "door_struct.h"

struct node *init(struct door *door) {
  struct node *lst;
  lst = (struct node *)malloc(sizeof(struct node));
  (*lst).data = *door;
  (*lst).next = NULL;
  return (lst);
}

struct node *add_door(struct node *elem, struct door *door) {
  struct node *temp, *p;
  temp = (struct node *)malloc(sizeof(struct node));
  p = elem->next;
  elem->next = temp;
  temp->data = *door;
  temp->next = p;
  return (temp);
}

struct node *remove_door(struct node *elem, struct node *root) {
  struct node *temp;
  temp = root;
  while (temp->next != elem) {
    temp = temp->next;
  }
  temp->next = elem->next;
  free(elem);
  return (temp);
}

struct node *find_door(int door_id, struct node *root) {
  struct node *temp;
  temp = root;
  while ((temp->next != NULL) && (temp->data.id != door_id)) {
    temp = temp->next;
  }
  if (temp->data.id != door_id) {
    return NULL;
  }
  return (temp);
}

void destroy(struct node *root) {
  while (root != NULL) {
    struct node *p = root;
    root = root->next;
    free(p);
  }
}
