public class Solution
{
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        if (nums1.Length > nums2.Length)
        {
            // Swap arrays
            return FindMedianSortedArrays(nums2, nums1);
        }
        else
        {
            // Calculate left and right pointers
            int left = 0;
            int right = nums1.Length;

            while (left <= right)
            {
                // Calculate partitions
                int p1 = (left + right) >> 1;
                int p2 = ((nums1.Length + nums2.Length + 1) >> 1) - p1;

                int l1 = (p1 == 0) ? Int32.MinValue : nums1[p1 - 1];
                int l2 = (p2 == 0) ? Int32.MinValue : nums2[p2 - 1];

                int r1 = (p1 == nums1.Length) ? Int32.MaxValue : nums1[p1];
                int r2 = (p2 == nums2.Length) ? Int32.MaxValue : nums2[p2];

                if ((l1 <= r2) && (l2 <= r1))
                {
                    int total = nums1.Length + nums2.Length;

                    if ((total % 2) != 0)
                    {
                        return (double)(Math.Max(l1, l2));
                    }
                    else
                    {
                        return (double)((Math.Max(l1, l2) + Math.Min(r1, r2)) / 2.0);
                    }
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
}