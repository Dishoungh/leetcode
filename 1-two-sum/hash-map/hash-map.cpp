#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            // Create map
            unordered_map<int, int> indicesMap;

            for (int i = 0; i < nums.size(); i++)
            {
                // Calculate the required number needed to add up to the target
                int required = target - nums[i];

                // Check if the required number is in the map
                if (indicesMap.find(required) != indicesMap.end())
                {
                    return {indicesMap[required], i};
                }

                // Store the current number and its index in the map
                indicesMap[nums[i]] = i;
            }

            return {};
        }
};