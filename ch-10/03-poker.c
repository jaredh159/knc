#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/* external variables */
int cards[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void) {
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
}

void read_cards(void) {
  char ch, rank_ch, suit_ch;
  int rank, suit, card_index = 0;
  bool bad_card;

  for (int i = 0; i < NUM_CARDS; i++) {
    cards[i][RANK] = 0;
    cards[i][SUIT] = 0;
  }

  while (card_index < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':
        exit(EXIT_SUCCESS);
      case '2':
        rank = 0;
        break;
      case '3':
        rank = 1;
        break;
      case '4':
        rank = 2;
        break;
      case '5':
        rank = 3;
        break;
      case '6':
        rank = 4;
        break;
      case '7':
        rank = 5;
        break;
      case '8':
        rank = 6;
        break;
      case '9':
        rank = 7;
        break;
      case 't':
      case 'T':
        rank = 8;
        break;
      case 'j':
      case 'J':
        rank = 9;
        break;
      case 'q':
      case 'Q':
        rank = 10;
        break;
      case 'k':
      case 'K':
        rank = 11;
        break;
      case 'a':
      case 'A':
        rank = 12;
        break;
      default:
        bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c':
      case 'C':
        suit = 0;
        break;
      case 'd':
      case 'D':
        suit = 1;
        break;
      case 'h':
      case 'H':
        suit = 2;
        break;
      case 's':
      case 'S':
        suit = 3;
        break;
      default:
        bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ')
        bad_card = true;

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (cards[rank][suit])
      printf("Duplicate card; ignored.\n");
    else {
      cards[card_index][RANK] = rank;
      cards[card_index][SUIT] = suit;
      card_index++;
    }
  }
}

void analyze_hand(void) {
  int num_consec = 0;
  int rank, suit;

  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  /* check for flush */
  if (cards[0][SUIT] == cards[1][SUIT] == cards[2][SUIT] == cards[3][SUIT] ==
      cards[4][SUIT]) {
    flush = true;
  }

  int num_in_rank[NUM_RANKS];
  for (int i = 0; i < NUM_RANKS; i++) {
    num_in_rank[i] = 0;
  }

  for (int i = 0; i < NUM_CARDS; i++) {
    num_in_rank[cards[i][RANK]] = num_in_rank[cards[i][RANK]] + 1;
  }

  /* check for straight */
  rank = 0;
  while (num_in_rank[rank] == 0) rank++;
  for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++) num_consec++;
  if (num_consec == NUM_CARDS) {
    straight = true;
    return;
  }

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rank[rank] == 4)
      four = true;
    if (num_in_rank[rank] == 3)
      three = true;
    if (num_in_rank[rank] == 2)
      pairs++;
  }
}

void print_result(void) {
  if (straight && flush)
    printf("Straight flush");
  else if (four)
    printf("Four of a kind");
  else if (three && pairs == 1)
    printf("Full house");
  else if (flush)
    printf("Flush");
  else if (straight)
    printf("Straight");
  else if (three)
    printf("Three of a kind");
  else if (pairs == 2)
    printf("Two pairs");
  else if (pairs == 1)
    printf("Pair");
  else
    printf("High card");

  printf("\n\n");
}
