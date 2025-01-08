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
    int* mergedArr = (int*)(malloc((nums1Size + nums2Size) * sizeof(int)));
    double median = 0;

    int i = 0, j = 0, k = 0;

    while ((i < nums1Size) && (j < nums2Size))
    {
        if (nums1[i] < nums2[j])
        {
            mergedArr[k++] = nums1[i++];
        }
        else
        {
            mergedArr[k++] = nums2[j++];
        }
    }

    while (i < nums1Size)
    {
        mergedArr[k++] = nums1[i++];
    }

    while (j < nums2Size)
    {
        mergedArr[k++] = nums2[j++];
    }

    if (((nums1Size + nums2Size) % 2) == 0)
    {
        int m1 = mergedArr[(nums1Size + nums2Size) >> 1];
        int m2 = mergedArr[((nums1Size + nums2Size) >> 1) - 1];

        median = (double)((m1 + m2) / 2.0);
    }
    else
    {
        median = (double)(mergedArr[(nums1Size + nums2Size) >> 1]);
    }

    free(mergedArr);
    return median;
}