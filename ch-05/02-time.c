#include <stdio.h>

int main(void) {
  int hours, minutes;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);
  char *am_pm = hours >= 12 ? "PM" : "AM";
  int display_hours = hours > 12 ? hours - 12 : hours;
  printf(
    "Equivalent 12-hour time: %d:%02d %s\n", display_hours, minutes, am_pm);
  return 0;
}
