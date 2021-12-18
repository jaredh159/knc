#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
void stack_overflow();
void stack_underflow();
bool is_empty(void);
bool is_full(void);
bool is_operand(char ch);
bool eval_expression(void);
void push(int num);
int pop(void);
void print_value(void);

int main(void) {
  make_empty();
  while (eval_expression())
    ;
}

bool eval_expression(void) {
  char ch;
  printf("Enter an RPN expression: ");
  for (;;) {
    scanf(" %c", &ch);
    if (ch == '=') {
      print_value();
      return true;
    } else if (!isdigit(ch) && !is_operand(ch)) {
      return false;
    } else if (is_operand(ch)) {
      int right = pop();
      int left = pop();
      switch (ch) {
        case '+':
          push(left + right);
          break;
        case '-':
          push(left - right);
          break;
        case '*':
          push(left * right);
          break;
        case '/':
          push(left / right);
          break;
      }
    } else {
      push(ch - '0');
    }
  }

  return true;
}

bool is_operand(char ch) {
  switch (ch) {
    case '+':
      return true;
    case '-':
      return true;
    case '*':
      return true;
    case '/':
      return true;
    default:
      return false;
  }
}

void print_value(void) {
  int value = pop();
  printf("Value of expression: %i\n", value);
  make_empty();
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

void push(int num) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = num;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return '\0';
  } else {
    return contents[--top];
  }
}

void stack_overflow() {
  printf("Expression too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow() {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}
