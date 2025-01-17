class Solution:
    def findCommonPrefix(self, s1, s2):
        s1_length = len(s1)
        s2_length = len(s2)

        for i in range(min(s1_length, s2_length)):
            if (s1[i] != s2[i]):
                # Cut off base string (s1)
                return s1[:i]
        
        # Default return
        if (s1_length <= s2_length):
            return s1
        else:
            return s2
    
    def divide(self, strs, left, right):
        # Boundary check
        if (left == right):
            return strs[left]
        else:
            middle = (left + right) // 2
            ls = self.divide(strs, left, middle)
            rs = self.divide(strs, (middle + 1), right)
            return self.findCommonPrefix(ls, rs)
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        else:
            return self.divide(strs, 0, len(strs) - 1)

        