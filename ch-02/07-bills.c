#include <stdio.h>

int main(void) {
  printf("Enter a dollar amount: ");

  int amount;
  scanf("%d", &amount);

  int num_twenties = amount / 20;
  amount = amount - (20 * num_twenties);
  int num_tens = amount / 10;
  amount = amount - (10 * num_tens);
  int num_fives = amount / 5;
  amount = amount - (10 * num_fives);

  printf("$20 bills: %d\n", num_twenties);
  printf("$10 bills: %d\n", num_tens);
  printf(" $5 bills: %d\n", num_fives);
  printf(" $1 bills: %d\n", amount);

  return 0;
}
