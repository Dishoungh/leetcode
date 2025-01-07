from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {};

        for value, key in enumerate(nums):
            required = target - key;

            # Check if required is in dictionary
            if required in hashMap:
                return [hashMap[required], value];
            else:
                hashMap[key] = value;
        
        return [];
        