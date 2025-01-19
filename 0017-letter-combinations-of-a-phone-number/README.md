# Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in any **order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![image](./1200px-telephone-keypad2svg.png)

Example 1:
```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

Example 2:
```
Input: digits = ""
Output: []
```

Example 3:
```
Input: digits = "2"
Output: ["a","b","c"]
```

Constraints:
- 0 <= digits.length <= 4
- `digits[i]` is a digit in the range `['2', '9']`.


# Solution: Depth First Search

I honestly don't feel like typing out the explanation as it's about 1 o'clock in the morning for me. So, I'll just lazily drop this [GeeksforGeeks link](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/).