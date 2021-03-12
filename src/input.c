#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT 100
void get_input(int c, char input_arr[]);

void main() {
  // Variables
  char input_arr[MAX_INPUT];
  int c;
  List *p;
  char *hist_getter;
  char **tokens;
  // Ask for user input.
  printf("Please enter a phrase: ");
  get_input(c, input_arr);
  tokens = tokenize(input_arr);
  print_tokens(tokens);
  free_tokens(tokens);
  p = init_history();
  add_history(p, input_arr);
  hist_getter = get_history(p, 0);
  printf("%s\n", hist_getter);
  print_history(p);
  free_history(p);
}

void get_input(int c, char input_arr[]) {
  int pointer = 0;
  while ((c = getchar()) != '\n') {
    input_arr[pointer] = c;
    pointer++;
  }
  input_arr[pointer] = '\0';
}
