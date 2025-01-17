class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        else:
            for j in range(len(strs[0])):
                for i in range(1, len(strs)):
                    if ((j == len(strs[i])) or (strs[i][j] != strs[0][j])): # Prefix no longer matches
                        # Return substring
                        return strs[0][:j]
            # Default return
            return strs[0]