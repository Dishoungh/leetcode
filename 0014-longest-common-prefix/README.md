# Description

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

 

Example 1:
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

Example 2:
```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```
 

Constraints:
- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters if it is non-empty.

# Solution 1: Linear Comparison

This algorithm simply works by using the first string in the string array as a base. Traverse through strs[0] and keep comparing all of the strings character by character. If there's a mismatch between the characters, return strs[0].

**Assuming M is the size of the strs array and N is the size of strs[0], the time complexity of this algorithm is `O(M * N)`.**

# Solution 2: Divide-and-Conquer

We will utilize a divide-and-conquer algorithm by dividing the string array into smaller subarrays. It will be the same thing as the Linear Comparison but we will compare each of the subarrays for the largest prefix.

**Assuming N is the largest string length in the array and M is the number of strings in the strs array, the time complexity is still `O(M * N)`, but the space complexity increases to `O(M * log(N))`

