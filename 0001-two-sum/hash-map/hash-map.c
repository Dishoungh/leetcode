/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    
    // Loop through the array
    for (int i = 0; i < numsSize; i++)
    {
        int required = target - nums[i];

        for (int j = 0; j < i; j++)
        {
            if (nums[j] == required)
            {
                
                result[0] = i;
                result[1] = j;

                return result;
            }
        }
    }
    
    *returnSize = 0; // No valid solution found
    free(result);
    return NULL;
}