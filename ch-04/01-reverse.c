#include <stdio.h>

int main(void) {
  printf("Enter a two-digit number: ");

  int num;
  scanf("%d", &num);

  int first_digit = num / 10;
  int last_digit = num % 10;

  printf("The reversal is: %d%d\n", last_digit, first_digit);

  return 0;
}
