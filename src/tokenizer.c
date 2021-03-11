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
  char *p = str;
  int x = non_space_char(*p);
  while (x == 0 && *p != '\0') {
    x = non_space_char(*p);
    if (x == 1) {
      break;
    }
    p++;
  }
  return p;
}

char *word_end(char *str){
  char *p = str;
  int x = space_char(*p);
  while (x == 0 && *p != '\0') {
    x = space_char(*p);
    if (x == 1) {
      break;
    }
    p++;
  }
  return p;
}

int count_words(char *str) {
  int counter = 0;
  for (char *p = str; *p != '\0'; p++) {
    if (*p == ' ' && *p != '\0'){
      p = word_end(p);
    }
    if (*p != ' ' && *p != '\0') {
      p = word_start(p);
      counter++;
    }
    if (p == NULL || *p == '\0'){
      break;
    }
  }
  printf("We found %d words in the phrase\n", counter);
  return counter;
}

char *copy_str(char *inStr, short len) {
  char *p = malloc(sizeof(char) * (len + 1));
  int i = 0;
  while (*inStr != '\0' && i < len) {
    p[i] = *inStr;
    inStr++;
    i++;
  }
  if (*inStr == '\0' && len == 1){
    p[i] = *inStr;
  }
  return p;
}

char **tokenize(char *str) {
  char *p_word = str;
  int words = count_words(str);
  char **tokens = (char **) malloc(sizeof(char *) * (words + 1));
  int traverser = 0;
  short len = 0;
  int spaces = 0;
  while (traverser <= words && *p_word != '\0'){
    for (char *p = p_word; *p != '\0' && *p != ' '; p++) {
      len++;
    }
    tokens[traverser] = copy_str(p_word, len);
    p_word += len;
    for (char *p = p_word; *p != '\0' && *p ==' '; p++) {
      spaces++;
    }
    p_word += spaces;
    len = 0;
    spaces = 0;
    traverser++;
  }
  tokens[traverser + 1] = copy_str(p_word, 0);
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
  tokens = NULL;
}
