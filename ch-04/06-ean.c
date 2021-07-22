#include <stdio.h>

int main(void) {
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
  printf("Enter the first 12 digits of an EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);

  int first_sum = d2 + d4 + d6 + d8 + d10 + d12;
  int second_sum = d1 + d3 + d5 + d7 + d9 + d11;
  int total = 3 * first_sum + second_sum;
  int check_digit = 9 - ((total - 1) % 10);

  printf("Check digit: %d\n", check_digit);
  return 0;
}
