class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            # Swap arrays
            return self.findMedianSortedArrays(nums2, nums1)
        else:
            left, right = 0, len(nums1)

            while left <= right:
                p1 = (left + right) // 2
                p2 = ((len(nums1) + len(nums2) + 1) // 2) - p1
                
                l1, l2, r1, r2 = float('-inf'), float('-inf'), float('inf'), float('inf')

                l1 = nums1[p1 - 1] if (p1 - 1 >= 0) else float('-inf')
                l2 = nums2[p2 - 1] if (p2 - 1 >= 0) else float('-inf')
                r1 = nums1[p1] if (p1 < len(nums1)) else float('inf')
                r2 = nums2[p2] if (p2 < len(nums2)) else float('inf')

                if l1 <= r2 and l2 <= r1:
                    if (len(nums1) + len(nums2)) % 2 == 1:
                        return max(l1, l2)
                    else:
                        return (float(max(l1, l2)) + float(min(r1, r2))) / 2.0
                elif l1 > r2:
                    right = p1 - 1
                else:
                    left = p1 + 1
        
        return float(0.0)


        