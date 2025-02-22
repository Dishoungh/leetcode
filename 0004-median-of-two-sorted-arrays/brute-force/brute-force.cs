public class Solution
{
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        int m = nums1.Length;
        int n = nums2.Length;
        int t = m + n;

        int[] mergedArr = new int[t];
        double median = 0.0;

        int i = 0;
        int j = 0;
        int k = 0;

        while ((i < m) && (j < n))
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

        while (i < m)
        {
            mergedArr[k++] = nums1[i++];
        }

        while (j < n)
        {
            mergedArr[k++] = nums2[j++];
        }

        if ((t % 2) == 0)
        {
            int a = mergedArr[t / 2];
            int b = mergedArr[(t / 2) - 1];

            median = (double)(a + b) / 2.0;
        }
        else
        {
            median = (double)(mergedArr[t / 2]);
        }

        return median;
    }
}