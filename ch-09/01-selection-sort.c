#include <limits.h>
#include <stdio.h>

void selection_sort(int nums[], int len);

// print the array, assume length of 5
// INT_MIN from limits.h

int main(void) {
  int nums[5];
  printf("Enter 5 numbers: ");

  scanf("%i %i %i %i %i", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

  selection_sort(nums, 5);

  printf("Ordered: ");
  printf("%i %i %i %i %i\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
}

void selection_sort(int nums[], int len) {
  if (len < 2) {
    return;
  }

  int largest = INT_MIN;
  int largest_index = -1;

  for (int i = 0; i < len; i++) {
    if (nums[i] > largest) {
      largest = nums[i];
      largest_index = i;
    }
  }

  int was_last = nums[len - 1];
  nums[len - 1] = largest;
  nums[largest_index] = was_last;
  return selection_sort(nums, len - 1);
}
