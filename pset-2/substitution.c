#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool key_valid(char* key);
char cipher_char(char ch, char* key);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  char* key = argv[1];
  if (!key_valid(key)) {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  char* plain_text = get_string("plaintext:  ");
  printf("ciphertext: ");

  for (int i = 0, n = strlen(plain_text); i < n; i++) {
    printf("%c", cipher_char(plain_text[i], key));
  }

  printf("\n");
  return 0;
}

char cipher_char(char ch, char* key) {
  if (!isalpha(ch)) {
    return ch;
  }

  bool is_uppercased = isupper(ch);
  ch = tolower(ch);
  int index = ch - 'a';
  char cipher_ch = key[index];
  return is_uppercased ? toupper(cipher_ch) : tolower(cipher_ch);
}

bool key_valid(char* key) {
  if (strlen(key) != 26) {
    return false;
  }

  for (int i = 0; i < 26; i++) {
    if (!isalpha(key[i])) {
      return false;
    }
  }

  return true;
}
