# Description

Given a string s, return the longest palindromic substring in s. 

Example 1:
```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

Example 2:
```
Input: s = "cbbd"
Output: "bb"
```

Constraints:
- 1 <= s.length <= 1000
- s consist of only digits and English letters.

# Solution 1: Dynamic Programming

This works by storing two pointers. During the traversal through the string, the low and high pointers will increment as long as the characters match. When the characters no longer match, it will capture the length of the palindrome (high - low + 1). If the length is greater than the current maximum length, update the maximum length.

**The time complexity of this algorithm is `O(N^2)`.**

# Solution 2: Manacher's Algorithm

To calculate the longest palindromic substring in linear time, we can use Manacher's Algorithm. See this [GeeksforGeeks article](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/) for more information about how the algorithm works.

**The time complexity of this algorithm is `O(N)`.**

