#include <stdio.h>

int main(void) {
  int item_number;
  printf("Enter item number: ");
  scanf("%d", &item_number);

  float unit_price;
  printf("Enter unit price: ");
  scanf("%f", &unit_price);

  printf("Enter purchase date (mm/dd/yy): ");
  int month, day, year;
  scanf("%d/%d/%d", &month, &day, &year);

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  printf("%d\t\t$%7.2f\t%d/%02d/%02d\n", item_number, unit_price, year, month, day);
  return 0;
}
