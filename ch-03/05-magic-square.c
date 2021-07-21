#include <stdio.h>

int main(void) {
  int nums[16];
  printf("Enter the numbers from 1 to 16 in any order: ");
  for (int i = 0; i < 16; i++)
    scanf("%d", &nums[i]);
  
  printf("%2d %2d %2d %2d\n", nums[0], nums[1], nums[2], nums[3]);
  printf("%2d %2d %2d %2d\n", nums[4], nums[5], nums[6], nums[7]);
  printf("%2d %2d %2d %2d\n", nums[8], nums[9], nums[10], nums[11]);
  printf("%2d %2d %2d %2d\n\n", nums[12], nums[13], nums[14], nums[15]);

  printf(
    "Row sums: %d %d %d %d\n",
    nums[0] + nums[1] + nums[2] + nums[3],
    nums[4] + nums[5] + nums[6] + nums[7],
    nums[8] + nums[9] + nums[10] + nums[11],
    nums[12] + nums[13] + nums[14] + nums[15]
    );
  printf(
    "Column sums: %d %d %d %d\n",
    nums[0] + nums[4] + nums[8] + nums[12],
    nums[1] + nums[5] + nums[9] + nums[13],
    nums[2] + nums[6] + nums[10] + nums[14],
    nums[3] + nums[7] + nums[11] + nums[15]
    );
  printf(
    "Diagonal sums: %d %d\n",
    nums[0] + nums[5] + nums[10] + nums[15],
    nums[12] + nums[9] + nums[6] + nums[3]
  );
  // 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
  return 0;
}
