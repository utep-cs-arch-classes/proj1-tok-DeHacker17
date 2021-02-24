#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
int count_char(char *str);

int space_char(char c) {
  if (c == ' ' || c == '\t' || c == '\n' && c != '\0') {
    return 0;
  }
  return 1;
}

int non_space_char(char c) {
  if (c != ' ' && c != '\t' && c != '\n' && c != '\0') {
    return 0;
  }
  return 1;
}

char *word_start(char *str) {
  return str;
}

char *word_end(char *str){
  char *p = str;
  *p = '\0';
  return p;
}

int count_words(char *str) {
  int length = count_char(str);
  char *pntr = NULL;
  int counter = 0;
  int space;
  int non_space;
  for (char *p_start = str; *p_start != '\0'; p_start++) {
    space = space_char(*p_start);
    non_space = non_space_char(*p_start);
    if (space == 0) {
      // printf("Char is a space: %c\n", *p_start);
      pntr = word_end(p_start);
    }
    else if (non_space == 0) {
      // printf("Char is not a space: %c\n", *p_start);
      pntr = word_start(p_start);
    }
    if (*(p_start + 1) != ' ' && *pntr == '\0' && *(p_start + 1) != '\0'){
      counter++;
    }
    else if(*(p_start + 1) == '\0' && *p_start != '\0'){
      counter++;
    }
  }
  return counter;
}

int count_char(char *str) {
  int counter = 0;
  for (char *p = str; *p != '\0'; p++) {
    counter++;
  }
  return counter;
}
