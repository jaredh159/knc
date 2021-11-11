#include <stdio.h>

int main(void) {
  int grid[5][5];

  for (int r = 0; r < 5; r++) {
    printf("Enter row %d: ", r + 1);
    scanf("%d %d %d %d %d", &grid[r][0], &grid[r][1], &grid[r][2], &grid[r][3],
      &grid[r][4]);
  }

  int row_totals[5] = {0};
  int col_totals[5] = {0};

  for (int row_idx = 0; row_idx < 5; row_idx++) {
    for (int col_idx = 0; col_idx < 5; col_idx++) {
      row_totals[row_idx] += grid[row_idx][col_idx];
      col_totals[col_idx] += grid[row_idx][col_idx];
    }
  }

  printf("Row totals: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", row_totals[i]);
  }

  printf("\nColumn totals: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", col_totals[i]);
  }

  printf("\n");
}
