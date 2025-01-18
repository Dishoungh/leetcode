using System;
using System.Collections;

public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        int size = nums.Length;

        // Sort array
        Array.Sort(nums);

        // Initialize return IList
        IList<IList<int>> result = new List<IList<int>>();

        for (int i = 0; i < (nums.Length - 2); i++)
        {
            // Skip duplicates
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                continue;
            }
            else
            {
                int j = i + 1;
                int k = nums.Length - 1;

                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];

                    if (sum == 0)
                    {
                        // Add triplet
                        result.Add(new List<int> {nums[i], nums[j], nums[k]});
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

        return result;
    }
}