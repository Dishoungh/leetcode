class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)

        if (n < 3):
            return 0
        else:
            # Sort array
            nums.sort()

            result = nums[0] + nums[1] + nums[2]

            for i in range(n):
                left  = i + 1
                right = n - 1

                while (left < right):
                    sum = nums[i] + nums[left] + nums[right]

                    currentDifference = abs(sum - target)
                    closestDifference = abs(result - target)

                    if (currentDifference < closestDifference):
                        result = sum
                    
                    # Update poitners
                    if (sum < target):
                        left += 1
                    elif (sum > target):
                        right -= 1
                    else:
                        return target
            
            # Default return
            return result
        