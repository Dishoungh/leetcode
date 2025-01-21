#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            int N = nums.size();

            // Initialize answer vector
            vector<vector<int>> result;

            // Sort the vector
            sort(nums.begin(), nums.end());

            for (int i = 0; i < N - 3; i++)
            {
                // Skip duplicates
                if ((i > 0) && (nums[i] == nums[i - 1]))
                {
                    continue;
                }
                else
                {
                    for (int j = i + 1; j < N - 2; j++)
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
                                long long sum = (long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[l];

                                if (sum < (long long) target)
                                {
                                    k++;
                                }
                                else if (sum > (long long) target)
                                {
                                    l--;
                                }
                                else
                                {
                                    result.push_back({nums[i], nums[j], nums[k], nums[l]});

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

            return result;
        }
};