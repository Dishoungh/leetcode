class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0):
            return False
        else:
            original = x
            reversed = 0

            LIMIT = 214748364

            # Store digits in reverse order in "reversed"
            while (x != 0):
                digit = x % 10

                # Check if we're going to overflow
                if ((reversed > LIMIT) or ((reversed == LIMIT) and (digit > 7))):
                    return False
                else:
                    reversed = (10 * reversed) + digit
                    x = x // 10
            return (original == reversed)