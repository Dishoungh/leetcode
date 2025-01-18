#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            // Initialize answer vector
            vector<vector<int>> result;

            // Sort the vector
            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size() - 2; i++)
            {
                // Skip duplicates
                if ((i > 0) && (nums[i] == nums[i - 1]))
                {
                    continue;
                }
                else
                {
                    int j = i + 1;
                    int k = nums.size() - 1;

                    while (j < k)
                    {
                        int sum = nums[i] + nums[j] + nums[k];

                        if (sum == 0)
                        {
                            result.push_back({nums[i], nums[j], nums[k]});
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
};