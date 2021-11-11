#include <ctype.h>
#include <stdio.h>

int main(void) {
  char ch;
  int letter_counts[26] = {0};

  printf("Enter first word: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      ch = tolower(ch);
      letter_counts[ch - 'a'] += 1;
    }
  }

  printf("Enter second word: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      ch = tolower(ch);
      letter_counts[ch - 'a'] -= 1;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (letter_counts[i] != 0) {
      printf("The words are NOT anagrams.\n");
      return 0;
    }
  }

  printf("The words are anagrams.\n");
  return 0;
}
