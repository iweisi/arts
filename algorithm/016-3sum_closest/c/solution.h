#define abs(a, b) (a > b ? a - b : b - a)
#include <stdio.h>
int threeSumClosest(int* nums, int numsSize, int target) {
  // 冒泡升序
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = 0; j < numsSize - i -1; j++) {
      if (nums[j] > nums[j + 1]) {
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
      }
    }
  }

  int closest = nums[0] + nums[1] + nums[2];
  for (int i = 0; i < numsSize; i++) {
    int left = i + 1;
    int right = numsSize - 1;

    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if ((target - sum) == 0) {
        return sum;
      }
fprintf(stderr, "%d + %d + %d = %d\n", nums[i], nums[left], nums[right], sum);
      if (abs(target, sum) > abs(target, closest)) {
        right--;
      } else {
        left++;
        closest = sum;
      }
fprintf(stderr, "closest = %d\n", closest);
      while (nums[left] == nums[left + 1]) left++;
      while (nums[right] == nums[right - 1]) right--;
    }
  }

  return closest;
}