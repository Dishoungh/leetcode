# Description

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2<sup>31</sup>, 2<sup>31</sup> - 1], then return 0.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

 

Example 1:
```
Input: x = 123
Output: 321
```

Example 2:
```
Input: x = -123
Output: -321
```

Example 3:
```
Input: x = 120
Output: 21
```

Constraints:
- -2<sup>31</sup> <= x <= 2<sup>31</sup> - 1

# Solution: Naive Approach

This solution is relatively simple. Traverse through the digits of `x` by performing modulus division (x % 10). We're treating the integer `x` as a queue by "popping" the digit. Let's use the number 256 as an example

While x is not zero, grab the current digit and "pop" the digit:
```
x = 256
result = 0

digit = x % 10 = 256 % 10 = 6
x = x / 10 = 256 / 10 = 25
```

After this, check if the result won't overflow or not. Overflow error occurs when the digit we're about to append to the result will cause it to either be less than -2147483648 or greater than 2147483647. In these cases, **return 0**.

So, the logic for this is relatively simple. If the result is less than -214748364, which is `INT_MIN / 10`, it doesn't matter what the digit is. It's going to overflow regardless. However, if it's equal to -214748364, we have to check what the current digit we popped from x is. If that digit is less than -8, then we're going to overflow.

For positive numbers, it's different. If the result is greater than 214748364, which is `INT_MAX / 10`, we'll overflow. If the result is equal to 214748364, check the current digit. If that digit is greater than 7, then overflow will occur.

Assuming none of the above conditions are true, then that means that overflow will not occur. Append the "popped" digit to the result: `result = (10 * result) + digit`.

After traversing through all of x's digits, return the result.

**Assuming N = the number of digits of x, the time complexity of this algorithm is O(N).**