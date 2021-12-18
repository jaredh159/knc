#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
char top = 0;

void make_empty(void);
void stack_overflow();
void stack_underflow();
void failure();
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);

int main(void) {
  char ch;
  make_empty();

  printf("Enter parentheses and/or braces: ");
  while ((ch = getchar()) != '\n') {
    if (ch == '(' || ch == '{') {
      push(ch);
      continue;
    }
    char popped = pop();
    if (ch == ')' && popped != '(') {
      failure();
    }
    if (ch == '}' && popped != '{') {
      failure();
    }
  }

  if (!is_empty()) {
    failure();
  }

  printf("Parentheses/braces are nested properly\n");
}

void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(char c) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = c;
}

char pop(void) {
  if (is_empty()) {
    stack_underflow();
    return '\0';
  } else {
    return contents[--top];
  }
}

void stack_overflow() {
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow() {
  failure();
}

void failure() {
  printf("Parentheses/braces NOT nested properly\n");
  exit(EXIT_SUCCESS);
}
