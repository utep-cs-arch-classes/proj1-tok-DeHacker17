#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define MAX_INPUT 100
void get_input(int c, char input_arr[]);

void main() {
  // Variables
  char input_arr[MAX_INPUT];
  int c;
  int chars = 0;
  int words = 0;
  // Ask for user input.
  printf("Please enter a phrase: ");
  get_input(c, input_arr);
  count_words(input_arr);
}

void get_input(int c, char input_arr[]) {
  int pointer = 0;
  while ((c = getchar()) != '\n') {
    input_arr[pointer] = c;
    pointer++;
  }
  input_arr[pointer] = '\0';
}
