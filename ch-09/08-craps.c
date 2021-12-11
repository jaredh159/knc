#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
  srand((unsigned)time(NULL));

  int wins = 0;
  int losses = 0;

  for (;;) {
    play_game() ? wins++ : losses++;

    char input;
    printf("\nPlay again? ");
    scanf(" %c", &input);
    printf("\n");

    if (input == 'n' || input == 'N') {
      printf("Wins: %d Losses: %d\n", wins, losses);
      return 0;
    }
  }
}

bool play_game(void) {
  int point;
  int rolled = roll_dice();
  printf("You rolled: %d\n", rolled);

  if (rolled == 7 || rolled == 11) {
    printf("You win!\n");
    return true;
  }

  if (rolled == 2 || rolled == 3) {
    printf("You lose!\n");
    return false;
  }

  point = rolled;
  printf("Your point is %d\n", point);
  for (;;) {
    rolled = roll_dice();
    printf("You rolled: %d\n", rolled);
    if (rolled == point) {
      printf("You win!\n");
      return true;
    } else if (rolled == 7) {
      printf("You lose!\n");
      return false;
    }
  }
}

int roll_dice(void) {
  int die1 = (rand() % 6) + 1;
  int die2 = (rand() % 6) + 1;
  return die1 + die2;
}
