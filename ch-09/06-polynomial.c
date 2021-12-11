#include <stdio.h>

int polynomial(int x);

int main(void) {
  printf("Enter a value for x: ");
  int x;
  scanf("%i", &x);
  printf("Polynomial: %i\n", polynomial(x));
}

int polynomial(int x) {
  return (3 * (x * x * x * x * x)) +
         (2 * (x * x * x * x) - (5 * (x * x * x)) - (x * x) + (7 * x) - 6);
}
