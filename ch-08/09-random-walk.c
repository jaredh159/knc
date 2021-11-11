#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum dir {
  LEFT,
  RIGHT,
  UP,
  DOWN,
};

bool move(int *x, int *y, char grid[10][10]);
bool can_move(int x, int y, char grid[10][10]);
void print_board(char grid[10][10]);
bool can_move_to(int dir, int x, int y, char grid[10][10]);

int main(void) {
  // printf("LEFT %d, RIGHT = %d, UP = %d, DOWN = %d\n", LEFT, RIGHT, UP, DOWN);
  srand((unsigned)time(NULL));
  char grid[10][10] = {
    {'A', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  };

  int x = 0, y = 0;
  for (char ch = 'A'; ch < 'Z'; ch++) {
    if (!move(&x, &y, grid)) {
      break;
    }
  }

  print_board(grid);
}

bool move(int *x, int *y, char grid[10][10]) {
  if (!can_move(*x, *y, grid)) {
    return false;
  }

  for (;;) {
    int dir = rand() % 4;
    if (can_move_to(dir, *x, *y, grid)) {
      char next_char = grid[*x][*y] + 1;
      switch (dir) {
        case UP:
          *y -= 1;
          break;
        case DOWN:
          *y += 1;
          break;
        case LEFT:
          *x -= 1;
          break;
        case RIGHT:
          *x += 1;
          break;
      }
      grid[*x][*y] = next_char;
      break;
    }
  }

  return true;
}

bool can_move(int x, int y, char grid[10][10]) {
  int proposed_x = x;
  int proposed_y = y;

  for (int dir = 0; dir < 4; dir++) {
    if (can_move_to(dir, x, y, grid)) {
      return true;
    }
  }

  return false;
}

void print_board(char grid[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c  ", grid[i][j]);
    }
    printf("\n");
  }
}

bool can_move_to(int dir, int x, int y, char grid[10][10]) {
  switch (dir) {
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
  }

  if (x < 0 || y < 0 || x > 9 || y > 9) {
    return false;
  }

  return grid[x][y] == '.';
}
