class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        size = len(nums)

        # Sort array
        nums.sort()

        # Initialize array of arrays
        result = []

        for i in range(size - 2):
            # Skip duplicates
            if ((i > 0) and (nums[i] == nums[i - 1])):
                continue
            else:
                j = i + 1
                k = size - 1

                while (j < k):
                    sum = nums[i] + nums[j] + nums[k]

                    if (sum == 0):
                        # Add triplet
                        result.append([nums[i], nums[j], nums[k]])

                        k -= 1

                        # Skip duplicates
                        while ((j < k) and (nums[k] == nums[k + 1])):
                            k -= 1
                    elif (sum > 0):
                        k -= 1
                    else:
                        j += 1
        return result