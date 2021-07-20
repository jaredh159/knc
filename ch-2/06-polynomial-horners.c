#include <stdio.h>

int main(void) {
  int x;
  printf("Enter a value for X: ");
  scanf("%d", &x);
  int polynomial = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
  printf("Polynomial: %d\n", polynomial);
  return 0;
}
