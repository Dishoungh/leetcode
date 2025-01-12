class Solution:
    def reverse(self, x: int) -> int:
        # Signed 32-bit Integer Range: [-2,147,483,648, 2,147,483,647]
        result = 0
        negative = 0
        LIMIT_L = -214748364
        LIMIT_H = 214748364

        # If negative, make x positive since Python seems to do modulo division slightly differently
        if (x < 0):
            negative = 1
            x *= -1

        while (x != 0):
            # Get current digit
            digit = x % 10
            x = int(x / 10)

            # Check to make sure result isn't overflowing
            if (result < LIMIT_L):
                return 0
            elif ((result == LIMIT_L) and (digit < -8)):
                return 0
            elif (result > LIMIT_H):
                return 0
            elif ((result == LIMIT_H) and (digit > 7)):
                return 0
            else:
                result = (10 * result) + digit
        return result if (negative == 0) else (-result)
        