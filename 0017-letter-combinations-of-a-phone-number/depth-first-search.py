class Solution:
    def dfs(self, index, digits, hmap, tmp, res):
        if (index == len(digits)):
            res.append(tmp)
            return
        else:
            for i in hmap[digits[index]]:
                self.dfs(index + 1, digits, hmap, tmp + i, res)

    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        HMAP = { "2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}

        if (len(digits) != 0):
            self.dfs(0, digits, HMAP, "", result)
        
        return result
        