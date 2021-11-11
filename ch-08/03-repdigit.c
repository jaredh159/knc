#include <stdbool.h>
#include <stdio.h>

bool prompt();

int main(void) {
  // bool terminate = false;
  //  bool has_repeat;
  for (;;) {
    bool should_exit = prompt();
    if (should_exit) {
      return 0;
    }
  }
}

bool prompt() {
  int digits_count[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  if (n <= 0) {
    return true;
  }

  while (n > 0) {
    digit = n % 10;
    digits_count[digit] = digits_count[digit] + 1;
    if (digits_count[digit] > 1) {
      puts("Repeated digit");
      return false;
    }
    n /= 10;
  }

  puts("No repeated digit");
  return false;
}
