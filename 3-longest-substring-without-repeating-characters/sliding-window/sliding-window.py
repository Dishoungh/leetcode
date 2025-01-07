class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        visited = {}
        maxLen = 0
        i = 0

        for j in range(len(s)):
            if s[j] in visited and visited[s[j]] >= i:
                i = visited[s[j]] + 1
            visited[s[j]] = j
            maxLen = max(maxLen, j - i + 1)

        return maxLen