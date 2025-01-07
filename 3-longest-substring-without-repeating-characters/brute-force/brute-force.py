class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        i = 0

        while (i < len(s)):
            count = [0] * 128
            j = i
            while (j < len(s)):
                # Get ASCII value of s[j]
                code = ord(s[j])
                if (count[code] != 0):
                    break
                else:
                    maxLen = max(maxLen, (j - i + 1))
                    count[code] = 1
                j += 1
            i += 1

        return maxLen