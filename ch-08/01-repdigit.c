#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int digits_count[10] = {0};
  int digit;
  long n;
  bool has_repeats = false;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digits_count[digit] = digits_count[digit] + 1;
    if (digits_count[digit] > 1) {
      has_repeats = true;
    }
    n /= 10;
  }

  if (!has_repeats) {
    puts("No repeated digit");
    return 0;
  }

  printf("Repeated digit(s): ");
  for (int i = 0; i < 10; i++) {
    if (digits_count[i] > 1) {
      printf("%d ", i);
    }
  }

  printf("\n");
  return 0;
}
