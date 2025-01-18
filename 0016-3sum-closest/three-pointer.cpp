#include <algorithm>

class Solution
{
    public:
        int threeSumClosest(vector<int>& nums, int target)
        {
            int n = nums.size();

            if (n < 3)
            {
                return 0;
            }
            else
            {
                // Sort the array
                sort(nums.begin(), nums.end());

                int result = nums[0] + nums[1] + nums[2];

                for (int i = 0; i < n; i++)
                {
                    int left  = i + 1;
                    int right = n - 1;

                    while (left < right)
                    {
                        int sum = nums[i] + nums[left] + nums[right];

                        int currentDifference = abs(sum - target);
                        int closestDifference = abs(result - target);

                        if (currentDifference < closestDifference) // Current sum is closer to target than result
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
};