class Solution
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            if (nums1.size() > nums2.size())
            {
                // Swap arrays
                return findMedianSortedArrays(nums2, nums1);
            }
            else
            {
                // Calculate left and right pointers
                int left  = 0;
                int right = nums1.size();

                while (left <= right)
                {
                    // Calculate partitions
                    int p1 = (left + right) >> 1;
                    int p2 = ((nums1.size() + nums2.size() + 1) >> 1) - p1;

                    int l1 = (!p1) ? INT_MIN : nums1[p1 - 1];
                    int l2 = (!p2) ? INT_MIN : nums2[p2 - 1];

                    int r1 = (p1 == nums1.size()) ? INT_MAX : nums1[p1];
                    int r2 = (p2 == nums2.size()) ? INT_MAX : nums2[p2];

                    if ((l1 <= r2) && (l2 <= r1))
                    {
                        return (double)(((nums1.size() + nums2.size()) % 2) ? (std::max(l1, l2)) : ((std::max(l1, l2) + std::min(r1, r2)) / 2.0));
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
};