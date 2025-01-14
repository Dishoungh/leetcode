class Solution:
    def getValue(self, c: str) -> int:
        if   c == 'M':
            return 1000
        elif c == 'D':
            return 500
        elif c == 'C':
            return 100
        elif c == 'L':
            return 50
        elif c == 'X':
            return 10
        elif c == 'V':
            return 5
        elif c == 'I':
            return 1
        else:
            return 0
    
    def romanToInt(self, s: str) -> int:
        length   = len(s)
        previous = 0
        result   = 0

        for i in range(length):
            current = self.getValue(s[i])

            # Add to result
            result += current

            if (current > previous): # Subtract result from previous value for special cases
                result -= (2 * previous)
            
            # Update previous
            previous = current
        
        return result