#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

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
  char *pntr = NULL;
  int counter = 0;
  int space;
  int non_space;
  for (char *p_start = str; *p_start != '\0'; p_start++) {
    space = space_char(*p_start);
    non_space = non_space_char(*p_start);
    if (space == 0) {
      pntr = word_end(p_start);
    }
    else if (non_space == 0) {
      pntr = word_start(p_start);
    }
    if (*(p_start + 1) != ' ' && *pntr == '\0' && *(p_start + 1) != '\0'){
      counter++;
    }
    else if(*(p_start + 1) == '\0' && *p_start != '\0'){
      counter++;
    }
  }
  printf("We found %d words in the phrase\n", counter);
  return counter;
}

char *copy_str(char *inStr, short len) {
  char *p = malloc(sizeof(char) * (len + 1));
  int i = 0;
  while (*inStr != '\0') {
    p[i] = *inStr;
    inStr++;
    i++;
  }
  return p;
}

char **tokenize(char *str) {
  char *p_word = str;
  int words = count_words(str);
  char **tokens = malloc(sizeof(char) * (words + 1));
  int traverser = 0;
  short len = 0;
  int jumper = 0;
  while (traverser < words){
    for (char *p_letter = p_word; *p_letter != '\0'; p_letter++) {
      len++;
      jumper++;
    }
    tokens[traverser] = copy_str(p_word, len);
    p_word += jumper + 1;
    len = 0;
    traverser++;
    jumper = 0;
  }
  return tokens;
}

void print_tokens(char **tokens) {
  int i = 0;
  while (tokens[i] != NULL){
    printf("Tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens) {
  free(tokens);
}
