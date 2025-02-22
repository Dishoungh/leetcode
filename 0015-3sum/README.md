# Description

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

Example 1:
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```

Example 2:
```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```

Example 3:
```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```
 

Constraints:
- 3 <= nums.length <= 3000
- -10<sup>5</sup> <= nums[i] <= 10<sup>5</sup>

# Solution: Three Pointer Method

This will keep track of 3 indexes. Traverse the nums array. For each index (i), keep track of j and k. j will be equal to (i + 1) while k will be equal to numsSize - 1.

While j is less than k, add nums[i] + nums[j] + nums[k] as the `sum`. If the sum is equal to 0, store it in the results array. To avoid duplicates, we sort the nums array and ensure that nums[k] isn't equal to nums[k + 1].

**The time complexity of this algorithm is `O(N^2)`.**
