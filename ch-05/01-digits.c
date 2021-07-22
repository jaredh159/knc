#include <stdio.h>

int main(void) {
  printf("Enter a number: ");

  int num, num_digits;
  scanf("%d", &num);

  if (num >= 1000) {
    num_digits = 4;
  } else if (num > 100) {
    num_digits = 3;
  } else if (num > 10) {
    num_digits = 2;
  } else {
    num_digits = 1;
  }

  printf("The number %d has %d digits\n", num, num_digits);
  return 0;
}
