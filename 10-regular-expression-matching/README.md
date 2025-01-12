# Description

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 
Example 1:
```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

Example 2:
```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

Example 3:
```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
``` 

Constraints:

- 1 <= s.length <= 20
- 1 <= p.length <= 20
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'.
- It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

# Solution 1: Static Recursion

For this solution, we will be recursively calling the match function, traversing backwards through the string. Since I'm lazy and I don't feel like typing the solution in detail, I'll just link this [GeeksforGeeks explanation](https://www.geeksforgeeks.org/implementing-regular-expression-matching/) that I got the solution from.

**Assuming M is the length of the pattern string and N is the length of the input string, the time complexity of this algorithm is `O((MxN)^2)` and the memory space complexity is `O(1)`.**

# Solution 2: Dynamic Programming

The issue with solution 1 is that we repeat a lot of subproblems. This slows down our original algorithm. We can simply improve it by initializing a giant 2D array that stores solutions to recursive calls the algorithm already solved.

The downside to this algorithm is that it uses a lot of memory since we need to store a 2D array.

**This approach improves our time complexity to `O(MXN)`, but now our space complexity is `O(MXN)`**