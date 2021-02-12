#include <stdio.h>

#define MAX_INPUT 100

int get_input(int c, int input_arr[]);
int space_char(char c);
int non_space_char(char c);

void main() {
  // Variables
  int input_arr[MAX_INPUT];
  int input_pointer;
  int c;
  // Second to ask for user input.
  printf("Please enter a phrase: ");
  input_pointer = get_input(c, input_arr);
  /*
  for (int i = 0; i < sizeof(input_arr); i++) {
    printf("%c" + input_arr[i]);
  }
  */
  printf("\n");
}

int get_input(int c, int input_arr[]) {
  int checker;
  int pointer = 0;
  char letter;
  while ((c = getchar()) != '\n' && c != EOF) {
    input_arr[pointer] = c;
    checker = space_char(input_arr[pointer]);
    if (checker == 0) {
      printf("Whitespace character: ");
      putchar(c);
      printf("\n");
    }
    checker = non_space_char(input_arr[pointer]);
    if (checker == 0) {
      printf("Non-whitespace character: ");
      putchar(c);
      printf("\n");
    }
    pointer++;
  }
  return 0;
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
