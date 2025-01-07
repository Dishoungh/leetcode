from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        for i in range(len(nums)):
            for j in range(len(nums)):
                sum = nums[i] + nums[j];

                if ((sum == target) and (i != j)):
                    return [i, j];
        return [];
        