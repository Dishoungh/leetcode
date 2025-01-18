public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        int n = nums.Length;

        if (n < 3)
        {
            return 0;
        }
        else
        {
            // Sort array
            Array.Sort(nums);

            int result = nums[0] + nums[1] + nums[2];

            for (int i = 0; i < n; i++)
            {
                int left  = i + 1;
                int right = n - 1;

                while (left < right)
                {
                    int sum = nums[i] + nums[left] + nums[right];

                    int currentDifference = Math.Abs(sum - target);
                    int closestDifference = Math.Abs(result - target);

                    if (currentDifference < closestDifference) // Current sum is closer, thus update result
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
                    else
                    {
                        return target;
                    }
                }
            }

            // Default return
            return result;
        }
    }
}