#include <stdio.h>

#define MAX_INPUT 100

void main() {
  char input[MAX_INPUT];
  int c;
  printf("Please enter a phrase: ");
  fgets(input, 100, stdin);
  printf("Phrase 1st way: %s", input);

  printf("Please enter another phrase: ");
  while ((c = getchar()) != '\n' && c != EOF){
    putchar(c);
  }
  printf("\n");
}