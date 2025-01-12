# Description

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows: `string convert(string s, int numRows);`
 

Example 1:
```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

Example 2:
```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

Example 3:
```
Input: s = "A", numRows = 1
Output: "A"
```

Constraints:
- 1 <= s.length <= 1000
- s consists of English letters (lower-case and upper-case), ',' and '.'.
- 1 <= numRows <= 1000

# Solution: Naive Approach

The solution to this isn't that fancy, which proves that sometimes the "naive" way of doing things isn't all that bad. All we have to do is traverse through an imaginary 2D array. The 2D array represents our zigzag.

We have 4 cases to consider:

### Case 1

In this case, if the original string length is equal to 1 or the number of rows is equal to 1 or the string length is equal to the number of rows, then simply return the original string as zigzag conversion is not possible.

### Case 2

In this case, we're on the outer edges of the zigzag, meaning that the row index is either 0 or (numRows - 1). In this case, the next column index is equal to `(2 * numRows) - 2`. Let's use Example 2 from above to demonstrate this:
```
P     I    N
A   L S  I G
Y A   H R
P     I
```

Let's convert this example to show the indexes to make this easier to understand.

```
Length = 14
numRows = 4

0           6           12

1       5   7       11  13

2   4       8   10

3           9

```

On the 1st and 4th rows (the edges), notice how the difference between the numbers on the columns are all 6. This 6 comes from (2 * numRows) - 2 = (2 * 4) - 2 = 8 - 2 = 6.

### Case 3

On the non-edges, the logic is a bit different. Let's bring back the example from earlier:

```
Length = 14
numRows = 4

0           6           12

1       5   7       11  13

2   4       8   10

3           9

```

Notice how on the middle 2 rows, the difference is different. When going down and then up the zigzag from the 2nd row, the difference is 4. When going up and then down the zigzag, the difference is only 2.

For the 3rd row, it's different. When going down and then up the zigzag, the difference is 2. When going up and then down, the difference is 4.

So, we have to set up a flag to indicate if we're going **down-then-up the zigzag, or up-then-down the zigzag**.

For the down-then-up case, the next index column is equal to `2 * (numRows - row) - 2`.

### Case 4

For the up-then-down case, the next index column is equal to `2 * row`

**The time complexity of this algorithm is `O(N)`**