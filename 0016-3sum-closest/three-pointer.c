#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return (*((int*) a) - *((int*) b));
}

int getAbsoluteValue(int a, int b)
{
    return (a > b) ? (a - b) : (b - a);
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    if (numsSize < 3)
    {
        return 0;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int result = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize; i++)
    {
        int left  = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            int currentDifference = getAbsoluteValue(sum, target);
            int closestDifference = getAbsoluteValue(result, target);

            if (currentDifference < closestDifference) // Current Sum is closer to target than the result (Update result)
            {
                result = sum;
            }
            
            // Update pointers
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else // If we find a sum that exactly equals to the target, return the target
            {
                return target;
            }
        } 
    }

    // Default return
    return result;
}