using System.Collections.Generic;

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        // Create dictionary to act as our hash map
        Dictionary<int, int> hashMap = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int required = target - nums[i];

            // Check the map
            if (hashMap.ContainsKey(required))
            {
                return new int[] { hashMap[required], i};
            }
            else
            {
                // Otherwise, store the key in the map
                hashMap[nums[i]] = i;
            }
        }

        return new int[0];
    }
}