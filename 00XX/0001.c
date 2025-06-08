#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Brute force approach.
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        int *result = malloc(2 * sizeof(int));
        result[0] = i;
        result[1] = j;
        *returnSize = 2;
        return result;
      }
    }
  }
  // We should never reach this (input guarantees a result).
  return NULL;
}
