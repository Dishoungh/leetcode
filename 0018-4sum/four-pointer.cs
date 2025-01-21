public class Solution
{
    public IList<IList<int>> FourSum(int[] nums, int target)
    {
        int N = nums.Length;

        // Sort array
        Array.Sort(nums);

        // Initialize return IList
        IList<IList<int>> result = new List<IList<int>>();

        for (int i = 0; i < (N - 3); i++)
        {
            // Skip duplicates
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                continue;
            }
            else
            {
                for (int j = (i + 1); j < (N - 2); j++)
                {
                    if ((j > (i + 1)) && (nums[j] == nums[j - 1]))
                    {
                        continue;
                    }
                    else
                    {
                        // Create two pointers
                        int k = j + 1;
                        int l = N - 1;

                        while (k < l)
                        {
                            // Calculate sum
                            long sum = (long) nums[i] + (long) nums[j] + (long) nums[k] + (long) nums[l];

                            if (sum < (long) target)
                            {
                                k++;
                            }
                            else if (sum > (long) target)
                            {
                                l--;
                            }
                            else
                            {
                                // Add quadtriplet
                                result.Add(new List<int> {nums[i], nums[j], nums[k], nums[l]});

                                k++;
                                l--;

                                // Skip duplicates
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

        return result;
    }
}