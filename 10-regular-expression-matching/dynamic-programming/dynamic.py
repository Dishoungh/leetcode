class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(p)
        n = len(s)

        # Initialize 2D array
        solved = [ [False] * 21 for i in range(21)]

        # Empty input string and empty pattern string
        solved[0][0] = True

        # Eliminate preceding characters with '*'
        j = 1
        while (j <= m):
            if ((p[j - 1] == '*') and (j > 1)):
                solved[0][j] = solved[0][j - 2]
            j += 1

        # Fill in the table
        i = 1
        while (i <= n):
            j = 1
            while (j <= m):
                if ((p[j - 1] == '.') or (s[i - 1] == p[j - 1])): # Normal character match
                    solved[i][j] = solved[i - 1][j - 1]
                elif ((p[j - 1] == '*') and (j >= 2)):
                    # Check zero or more occurrence preceeding '*'
                    solved[i][j] = (solved[i][j - 2] or (solved[i - 1][j] and ((s[i - 1] == p[j - 2]) or (p[j - 2] == '.'))))
                else:
                    j += 1
                    continue
                j += 1
            i += 1
        return solved[n][m]

        