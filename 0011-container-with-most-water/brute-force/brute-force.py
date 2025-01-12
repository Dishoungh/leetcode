class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        max_area = 0

        for i in range(n):
            for j in range(n):
                area = (j - i) * min(height[i], height[j]) # Area = width * height
                max_area = max(area, max_area)
        
        return max_area