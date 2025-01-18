#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b)
{
    return (*((int*) a) - *((int*) b));
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Set Return Size;
    *returnSize = 0;

    // Initialize Result Array
    int** array2d = (int**) calloc((numsSize * numsSize), sizeof(int*));

    // Initialize *returnColumnSizes Array
    *returnColumnSizes = (int*) calloc((numsSize * numsSize), sizeof(int));

    for (int i = 0; i < numsSize - 2; i++)
    {
        // Skip duplicates
        if ((i > 0) && (nums[i] == nums[i - 1]))
        {
            continue;
        }
        else
        {
            int j = i + 1;
            int k = numsSize - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (!sum)
                {
                    // Add triplet to array2d
                    array2d[*returnSize] = (int*) malloc(3 * sizeof(int));

                    array2d[*returnSize][0] = nums[i];
                    array2d[*returnSize][1] = nums[j];
                    array2d[*returnSize][2] = nums[k];

                    // Update returnColumnSizes
                    (*returnColumnSizes)[*returnSize] = 3;

                    // Update *returnSize
                    (*returnSize)++;
                    k--;

                    // Skip duplicates
                    while ((j < k) && (nums[k] == nums[k + 1]))
                    {
                        k--;
                    }
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
    }

    return array2d;
}