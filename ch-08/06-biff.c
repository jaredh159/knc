#include <ctype.h>
#include <stdio.h>

char biffize(char);

int main(void) {
  char chars[50] = {'\0'};
  int index = 0;
  char ch;

  printf("Enter message: ");

  while ((ch = getchar()) != '\n') {
    chars[index++] = ch;
  }

  printf("In B1FF-speak: ");

  index = 0;
  for (;;) {
    if (chars[index]) {
      printf("%c", biffize(chars[index++]));
    } else {
      printf("!!!!!!!!!\n");
      return 0;
    }
  }
}

char biffize(char ch) {
  ch = toupper(ch);
  switch (ch) {
    case 'A':
      return '4';
    case 'B':
      return '8';
    case 'E':
      return '3';
    case 'I':
      return '1';
    case 'O':
      return '0';
    case 'S':
      return '5';
    default:
      return ch;
  }
}
