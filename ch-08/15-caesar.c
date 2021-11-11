#include <ctype.h>
#include <stdio.h>

char encrypt(char ch, int n);

int main(void) {
  char message[80];
  char ch;
  int n;

  printf("Enter message to be encrypted: ");
  for (int i = 0; i < 80; i++) {
    ch = getchar();
    if (ch != '\n') {
      message[i] = ch;
    } else {
      break;
    }
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &n);

  printf("Encrypted message: ");
  for (int i = 0; i < 80 && message[i]; i++) {
    printf("%c", encrypt(message[i], n));
  }
  printf("\n");
}

char encrypt(char ch, int n) {
  if (!isalpha(ch)) {
    return ch;
  }
  if (isupper(ch)) {
    return ((ch - 'A') + n) % 26 + 'A';
  }
  return ((ch - 'a') + n) % 26 + 'a';
}
