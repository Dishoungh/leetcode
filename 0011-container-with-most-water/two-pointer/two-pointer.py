class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        max_area = 0
        left = 0
        right = n - 1

        while (left < right):
            #Area = width (right - left) * height (min(height[left], height[right]))
            area = (right - left) * min(height[left], height[right])

            # Update max_area
            max_area = max(area, max_area)
            
            # Update pointers
            if (height[left] < height[right]):
                left += 1
            else:
                right -= 1
        return max_area