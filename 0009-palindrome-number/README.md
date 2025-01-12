# Description

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

Example 2:
```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

Example 3:
```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

Constraints:
- -2<sup>31</sup> <= x <= 2<sup>31</sup> - 1

# Solution: Yet Another Simple Method

This algorithm is pretty easy. All we have to do is just make 2 variables: `original` and `reversed`. `original` simply just copies the value of x. `reversed` will append x's digits in reverse order.

To check if x is a palindrome, simply check if `original` and `reversed` are equal.

If x is a negative number, it doesn't count according to leetcode's rules since the negative symbol counts as a digit. Of course, we have to check if the reversed number is going to overflow. If so, then return false.

**Assuming N is the number of digits of x, the time complexity of this algorithm is `O(N)`.**
