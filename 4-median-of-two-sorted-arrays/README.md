# Description

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
``` 

Constraints:
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -10<sup>6</sup> <= nums1[i], nums2[i] <= 10<sup>6</sup>

# Solution 1: Brute Force

This solution simply works by creating a total array that will combine the two sorted arrays. Since the arrays are already sorted, we don't have to waste much time. All we have to do to combine the two arrays is simply create three index pointers: one for nums1 (i), one for nums2 (j), and one for the total array (k). If nums1[i] is less than nums2[j], put nums1[i] in totalArr[k] and increment both i and k. Otherwise, put nums2[j] in totalArr[k] and increment both j and k.

After all the elements are placed in the merged array, simply calculate the sum of the sizes. If the sum of the sizes is an even number, that means the median will be the average of the two middle numbers. Otherwise, the median will be number in the middle of the merged array.

**The time complexity of this algorithm is `O(n)`.**

# Solution 2: Binary Search (Divide-and-Conquer)

This solution works by recursively dividing the array into halves. It's similar to how the quick sort algorithm works. We ensure that the first array (nums1) is smaller than the second (nums2). If not, swap the array pointers and sizes.

Calculate the length of the left half. Place low and high pointers at 0 and the nums1 size respectively. Calculate the first pivot (p1) and second pivot (p2).

- p1 = (low + high) / 2
- p2 = ((nums1Size + nums2Size + 1) >> 1) - p1;

Store more variables:

- l1 = nums1[p1 - 1]
- l2 = nums2[p2 - 1]
- r1 = nums1[p1]
- r2 = nums2[p2]

If (l1 <= r2) and (l2 <= r1), return the median. Otherwise, adjust the left and right pointers. If l1 is greater than r2, the right pointer will be updated to (p1 - 1). Otherwise, the left pointer will be updated to (p1 + 1).

**The time complexity of this algorithm is `O(log(n))`.**