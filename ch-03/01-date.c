#include <stdio.h>

int main(void) {
  printf("Enter a date (mm/dd/yyyy): ");

  int month, day, year;
  scanf("%d/%d/%d", &month, &day, &year);

  printf("You entered the date %d%02d%02d\n", year, month, day);
  return 0;
}
