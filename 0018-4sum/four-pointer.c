#include <stdint.h>
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

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Set Return Size
    *returnSize = 0;

    // Initialize return array
    int** quads = (int**) calloc((4 * numsSize), sizeof(int*));

    // Initialize *returnColumnSizes array
    *returnColumnSizes = (int*) calloc((4 * numsSize), sizeof(int));

    for (int i = 0; i < (numsSize - 3); i++)
    {
        // Skip duplicates
        if ((i > 0) && (nums[i] == nums[i - 1]))
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < (numsSize - 2); j++)
            {
                if ((j > (i + 1)) && (nums[j] == nums[j - 1]))
                {
                    continue;
                }
                else
                {
                    //Create two pointers
                    int k = j + 1;
                    int l = numsSize - 1;

                    while (k < l)
                    {
                        // Calculate sum
                        int64_t sum = (int64_t) nums[i] + (int64_t) nums[j] + (int64_t) nums[k] + (int64_t) nums[l];

                        if (sum < (int64_t) target) // If sum is less than target, move left pointer (k) over one to the right
                        {
                            k++;
                        }
                        else if (sum > (int64_t) target) // If sum is greater than target, move right pointer (l) over one to the left
                        {
                            l--;
                        }
                        else // If sum is equal, then add to quads array result
                        {
                            quads[*returnSize] = (int*) malloc(4 * sizeof(int));
                            quads[*returnSize][0] = nums[i];
                            quads[*returnSize][1] = nums[j];
                            quads[*returnSize][2] = nums[k];
                            quads[*returnSize][3] = nums[l];

                            // Update returnColumnSizes
                            (*returnColumnSizes)[*returnSize] = 4;

                            // Update *returnSize
                            (*returnSize)++;

                            //Skip duplicates for 3rd number
                            k++;
                            l--;
                            while ((k < l) && (nums[k] == nums[k - 1]))
                            {
                                k++;
                            }

                            //Skip duplicates for 4th number
                            while ((k < l) && (nums[l] == nums[l + 1]))
                            {
                                l--;
                            }
                        }
                    }
                }
            }
        }
    }

    return quads;
}