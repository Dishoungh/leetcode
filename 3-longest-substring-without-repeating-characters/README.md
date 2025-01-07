# Description

Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

Example 2:
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

Example 3:
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

# Solution 1: Brute Force

This will simply have two loops. In the inner loop, we will count until we reach the end of the array or we encounter a repeating character. When this happens, record the distance between the outer pointer (i) and the inner pointer (j). If the distances (j - i + 1) is greater than the current maximum, update the maximum.

**The time complexity of this solution is `O(n^2).`**

# Solution 2: Sliding Window Method

This method works by placing all possible ASCII characters (128) into an array and keeping a count of how many times those characters have been visited. Also store an index count of the left and right side of the window. The window keeps track of how long the substring is. While traversing through the array (incrementing the right index), keep track of the length of the window, which is the difference between the right and left indexes.

Once a repeating character is encountered, increment the left index and update the maximum length. If the current window size is greater than the maximum length, the current window size is the new max. Otherwise, keep the maximum the same. Once the right index reaches the end of the array, return the maximum size.

**The time complexity of this solution is `O(n).`**