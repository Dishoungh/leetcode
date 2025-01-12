# Description

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the i<sup>th</sup> line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.

Example 1:

![Image](./container-with-most-water.jpg)
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

Example 2:
```
Input: height = [1,1]
Output: 1
```

Constraints:
- 2 <= height.length <= 10<sup>5</sup>
- 0 <= height[i] <= 10<sup>4</sup>

# Solution 1: Brute Force

This algorithm is simple to understand but inefficient. The mechanics is similar to selection sorting. We will simply compare all possibile areas in the array with index `i` and `j`. Initialize `max_area` to 0. When the area (`height[i] * height[j])`) is greater than `max_area`, then update `max_area` to the currently measured area.

**The time complexity of this algorithm is `O(N^2)`.**

# Solution 2: Two Pointer

Unfortunately, the time complexity for the brute force method is too high to submit those versions. To improve the time complexity of the brute force method, we will use two indexes `left` and `right`. We don't need to compare all possible areas. We only need to update `max_area` when the measured area is greater.

So, for this algorithm, we can just initialize `left` to 0 (the first element in the array) and `n - 1` (the last element in the array). Area = `width * height`, so at this point, we are at the maximum width. As we're traversing through the area, we're decreasing the width, but we're looking for a height that's **great enough** to increase the `max_area`.

If `height[left]` is less than `height[right]` then, increment the left pointer. Otherwise, decrement the right pointer. Continue until `left >= right`.

**The time complexity of this algorithm is `O(N)`.**