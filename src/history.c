#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history() {
  struct s_List *p = (struct s_List*) malloc(sizeof(struct s_List) * 10);
  p->root = malloc(sizeof(struct s_Item));
  p->root->id = 0;
  return p;
}

void add_history(List *list, char *str) {
  Item *temp = list->root;
  int i = 0;
  while (temp->next != NULL) {
    temp->str = str;
    temp->next = malloc(sizeof(struct s_Item));
    temp->next->id = i;
    i++;
  }
}

char *get_history(List *list, int id) {
  Item *temp = list->root;
  char *word = list->root->str;
  if (id == 0){
    return word;
  }
  for (int i = 0; i == id && temp->next != NULL; i++){
    temp = temp->next;
    word = temp->str;
  }
  return word;
}

void print_history(List *list) {
  Item *temp = list->root;
  while (temp->next != NULL) {
    printf("%s\n", temp->str);
    temp = temp->next;
  }
}

void free_history(List *list) {
  Item *temp = list->root;
  while(temp->next != NULL) {
    free(temp);
    temp = temp->next;
  }
  free(list);
}
