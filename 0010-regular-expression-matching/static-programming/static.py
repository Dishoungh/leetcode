class Solution:
    def isMatchHelper(self, s: str, p: str, a: int, b: int) -> bool:
        # If pattern is empty, input string must also be empty
        if (b == 0):
            return (a == 0)

        # If input string is empty, pattern must have characters followed by "*"
        if (a == 0):
            # Check if pattern string is at least 2 and has a "*" at the end. If so, then return isMatchHelper(s, p, a, b - 2)
            return ((b >= 2) and (p[b - 1] == '*') and self.isMatchHelper(s, p, a, b - 2))

        # If last character of both input and pattern strings match or has '.'
        if ((s[a - 1] == p[b - 1]) or (p[b - 1] == '.')):
            return self.isMatchHelper(s, p, a - 1, b - 1)

        # If there is a '*' in the pattern
        if ((p[b - 1] == '*') and (b >= 2)):
            # Check if the preceding character zero or more times
            return ((self.isMatchHelper(s, p, a, b - 2)) or (((s[a - 1] == p[b - 2]) or (p[b - 2] == '.')) and self.isMatchHelper(s, p, a - 1, b)))

        #// Default return
        return False

    def isMatch(self, s: str, p: str) -> bool:
        return self.isMatchHelper(s, p, len(s), len(p))
        