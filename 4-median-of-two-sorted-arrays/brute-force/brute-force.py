class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        t = m + n

        mergedArr = [0] * t
        median = 0.0

        i = 0
        j = 0
        k = 0

        while ((i < m) and (j < n)):
            if (nums1[i] < nums2[j]):
                mergedArr[k] = nums1[i]
                k += 1
                i += 1
            else:
                mergedArr[k] = nums2[j]
                k += 1
                j += 1
        
        while (i < m):
            mergedArr[k] = nums1[i]
            k += 1
            i += 1
        
        while (j < n):
            mergedArr[k] = nums2[j]
            k += 1
            j += 1
        
        if ((t % 2) == 0):
            a = mergedArr[int(t / 2)]
            b = mergedArr[int(t / 2) - 1]

            median = float((a + b) / 2.0)
        else:
            median = float(mergedArr[int(t / 2)])
        
        return median


        