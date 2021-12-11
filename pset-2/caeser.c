#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(void);
char shift_char(char ch, int key);

// must use get_string()
// make a function to shift a character by X
// test that with 1 it makes a->b, b->c, ... z->a
// test that with 1 it makes A->B, B->C, ... Z->A
// use `https://www.asciichart.com/`
int main(int argc, string argv[]) {
  if (argc != 2) {
    print_usage();
    return 1;
  }

  for (int i = 0, len = strlen(argv[1]); i < len; i++) {
    if (!isdigit(argv[1][i])) {
      print_usage();
      return 1;
    }
  }

  int key = atoi(argv[1]);
  if (key <= 0) {
    print_usage();
    return 1;
  }

  string plain_text = get_string("plaintext:  ");

  printf("ciphertext: ");
  for (int i = 0, len = strlen(plain_text); i < len; i++) {
    printf("%c", shift_char(plain_text[i], key));
  }
  printf("\n");
}

char shift_char(char ch, int key) {
  if (islower(ch)) {
    return (((ch - 'a') + key) % 26) + 97;
  } else if (isupper(ch)) {
    return (((ch - 'A') + key) % 26) + 65;
  } else {
    return ch;
  }
}

void print_usage(void) {
  printf("Usage ./caesar key\n");
}
