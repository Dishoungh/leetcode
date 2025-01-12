class Solution:
    def longestPalindrome(self, s: str) -> str:
        if (len(s) == 1):
            return s
        else:
            N = 2 * len(s) + 1

            # LPS Array
            LPS = [0] * N
            LPS[0] = 0
            LPS[1] = 1

            l = 0 # Current Left Position
            c = 1 # Center Position
            r = 2 # Center Right Position

            # Other Variables
            maxLPSLength = 0
            maxLPSPosition = 0

            for i in range(2, N):
                # Get Current Left Position
                l = 2 * c - i

                # If current right position is within center right
                diff = r - i
                if (diff > 0):
                    LPS[i] = min(LPS[l], diff)
                
                # Expand palindrome
                try:
                    while ((i+LPS[i]) < N and (i-LPS[i]) > 0) and (((i+LPS[i]+1) % 2 == 0) or (s[(i+LPS[i]+1)//2] == s[(i-LPS[i]-1)//2])): 
                        LPS[i] += 1
                except Exception as e:
                    pass
                
                # Update maxLPSLength
                if LPS[i] > maxLPSLength:
                    maxLPSLength = LPS[i]
                    maxLPSPosition = i
                
                # Adjust expanded palindrome center position
                if ((i + LPS[i]) > r):
                    c = i
                    r = i + LPS[i]

            start = (maxLPSPosition - maxLPSLength) // 2
            end = start + maxLPSLength

            return s[start:end]