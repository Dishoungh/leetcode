class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        N = len(nums)

        # Sort array
        nums.sort()

        # Initialize array of arrays
        result = []

        for i in range(N - 3):
            # Skip duplicates
            if ((i > 0) and (nums[i] == nums[i - 1])):
                continue
            else:
                for j in range((i + 1), (N - 2)):
                    # Skip duplicates
                    if ((j > (i + 1)) and (nums[j] == nums[j - 1])):
                        continue
                    else:
                        # Create two pointers
                        k = j + 1
                        l = N - 1

                        while (k < l):
                            s = nums[i] + nums[j] + nums[k] + nums[l]

                            if (s < target):
                                k += 1
                            elif (s > target):
                                l -= 1
                            else:
                                # Add quadtriplet
                                result.append([nums[i], nums[j], nums[k], nums[l]])

                                k += 1
                                l -= 1

                                # Skip duplicates
                                while ((k < l) and (nums[k] == nums[k - 1])):
                                    k += 1
                                
                                while ((k < l) and (nums[l] == nums[l + 1])):
                                    l -= 1
        return result