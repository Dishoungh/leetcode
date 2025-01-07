#include <limits.h>
#include <stdlib.h>

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
    {
        // Swap arrays
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    else
    {
        int left  = 0;
        int right = nums1Size;
        
        while (left <= right)
        {
            int p1 = (left + right) >> 1;
            int p2 = ((nums1Size + nums2Size + 1) >> 1) - p1;

            int l1 = (!p1) ? INT_MIN : nums1[p1 - 1];
            int l2 = (!p2) ? INT_MIN : nums2[p2 - 1];

            int r1 = (p1 == nums1Size) ? INT_MAX : nums1[p1];
            int r2 = (p2 == nums2Size) ? INT_MAX : nums2[p2];

            if ((l1 <= r2) && (l2 <= r1))
            {
                return (double)(((nums1Size + nums2Size) % 2) ? (max(l1, l2)) : ((max(l1, l2) + min(r1, r2)) / 2.0));
            }
            else if (l1 > r2)
            {
                right = p1 - 1;
            }
            else
            {
                left = p1 + 1;
            }
        }

    }

    return (double) 0.0;
}