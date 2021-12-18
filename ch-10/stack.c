#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(int c) {
  if (is_full())
    stack_overflow();  // you have to define this
  else
    contents[top++] = c;
}

int pop(void) {
  if (is_empty())
    stack_underflow();  // you have to define this
  else
    return contents[--top];
}
