#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define MAX_INPUT 100
void get_input(int c, char input_arr[]);
int count_char(char *str);

void main() {
  // Variables
  char input_arr[MAX_INPUT];
  int c;
  int chars = 0;
  int words = 0;
  // Ask for user input.
  printf("Please enter a phrase: ");
  get_input(c, input_arr);
  printf("\n");
  chars = count_char(input_arr);
  words = count_words(input_arr);
  printf("Number of chars: %d\n", chars);
  printf("Number of words: %d\n", words);
}

void get_input(int c, char input_arr[]) {
  int pointer = 0;
  while ((c = getchar()) != '\n') {
    putchar(c);
    input_arr[pointer] = c;
    pointer++;
  }
  input_arr[pointer] = '\0';
}

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
    if (*(p_start + 1) != ' ' && *pntr == '\0'){
      counter++;
    }
  }
  return counter;
}

int count_char(char *str) {
  int counter = 0;
  printf("Printing phrase with pointers: ");
  for (char *p = str; *p != '\0'; p++) {
    printf("%c", *p);
    counter++;
  }
  printf("\n");
  return counter;
}
