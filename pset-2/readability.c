#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char* text = get_string("Text: ");

  int num_letters = 0;
  int num_words = 1;
  int num_sentences = 0;

  for (int i = 0, n = strlen(text); i < n; i++) {
    if (text[i] == ' ') {
      num_words++;
    }
    if (isalpha(text[i])) {
      num_letters++;
    }
    if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
      num_sentences++;
    }
  }

  float L = ((float)num_letters / (float)num_words) * 100.0;
  float S = ((float)num_sentences / (float)num_words) * 100.0;
  float f_grade = 0.0588 * L - 0.296 * S - 15.8;
  int grade = (int)f_grade;

  // GOTCHA: round to nearest whole number
  if ((f_grade - (float)grade) > 0.5) {
    grade++;
  }

  if (grade < 1) {
    printf("Before Grade 1\n");
  } else if (grade > 16) {
    printf("Grade 16+\n");
  } else {
    printf("Grade %d\n", grade);
  }
}
