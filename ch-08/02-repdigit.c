#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int digits_count[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digits_count[digit] = digits_count[digit] + 1;
    n /= 10;
  }

  printf("Digit:      ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", i);
  }

  printf("\nOccurences: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", digits_count[i]);
  }

  printf("\n");
  return 0;
}
