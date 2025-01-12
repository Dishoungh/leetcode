# Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

```
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 ```

Constraints:
- 2 <= nums.length <= 10<sup>4</sup>
- -10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>
- -10<sup>9</sup> <= target <= 10<sup>9</sup>
- **Only one valid answer exists.**

<br>

# Solution 1: Brute Force

This is the simplest approach. All I'm doing is making a nested for loop. The outer for loop will traverse through each element with i. The inner for loop will traverse through each element with j. Each iteration will calculate the sum as arr[i] + arr[j]. If (arr[i] + arr[j]) equals the target, then return the result array with i and j as the elements. Otherwise, return an empty array or NULL. 

**The time complexity of this solution is `O(N^2)`.**

# Solution 2: Hash Map

This method utilizes a hash map, which is a data structure that associates a key with a value, which speeds up the search time. What I'll do is for each iteration of the array is to calculate the difference of the target value and the number in the current iteration of the array. The hash map will be used to find the index of the difference number already included in the map, if it exists.

**The time complexity of this solution is `O(n).`**