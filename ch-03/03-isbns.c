#include <stdio.h>

int main(void) {
  int prefix, identifier, pub_code, item_number, check_digit;
  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &prefix, &identifier, &pub_code, &item_number, &check_digit);
  
  printf("GS1 prefix: %d\n", prefix);
  printf("Group identifier: %d\n", identifier);
  printf("Publisher code: %d\n", pub_code);
  printf("Item number: %d\n", item_number);
  printf("Check digit: %d\n", check_digit);

  return 0;
}
