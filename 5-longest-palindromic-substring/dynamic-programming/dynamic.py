class Solution:
    def longestPalindrome(self, s: str) -> str:
        start       = 0
        maxLength   = 1

        N           = len(s)
        arr = [[False] * N for x in range(N)]

        # Initialize Array
        for i in range(N):
            arr[i][i] = True
        
        # Check Matching Substrings of Length 2
        for i in range(N - 1):
            if s[i] == s[i + 1]:
                arr[i][i + 1] = True
                start = i
                maxLength = 2
        
        # Traverse
        for i in range(3, N + 1):
            for j in range(N - i + 1):
                k = i + j - 1

                if (arr[j + 1][k - 1]) and (s[j] == s[k]):
                    arr[j][k] = True

                    if i > maxLength:
                        start = j
                        maxLength = i
        
        return s[start:start + maxLength]

        