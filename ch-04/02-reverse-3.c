#include <stdio.h>

int main(void) {
  printf("Enter a three-digit number: ");

  int num;
  scanf("%d", &num);

  int first_digit = num / 100;
  int middle_digit = num / 10 % 10;
  int last_digit = num % 10;

  printf("The reversal is: %d%d%d\n", last_digit, middle_digit, first_digit);

  return 0;
}
