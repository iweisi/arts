#include <stdlib.h>
#include <stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
  int** results = calloc(numsSize * 3, sizeof(int*));
  int len = 0;

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      int a = nums[i] + nums[j];
      for (int k = j + 1; k < numsSize; k++) {
        if (a + nums[k]) {
          continue;
        }

        int min = nums[i] < nums[j] ? nums[i] : nums[j];
        min = min < nums[k] ? min : nums[k];
        int max = nums[i] > nums[j] ? nums[i] : nums[j];
        max = max > nums[k] ? max : nums[k];
        int mid = nums[i];
        if (min < nums[j] && nums[j] < max) mid = nums[j];
        if (min < nums[k] && nums[k] < max) mid = nums[k];
        if (nums[j] == nums[k]) mid = nums[j];

        int equal = 0;
        for (int l = 0; l < len; l++) {
          if (min == results[l][0] && max == results[l][2]) {
            equal = 1;
          }
        }

        if (equal) {
          continue;
        }

        results[len] = calloc(3, sizeof(int));
        results[len][0] = min;
        results[len][1] = mid;
        results[len][2] = max;
        len++;
      }
    }
  }

  *returnSize = len;
  return results;
}