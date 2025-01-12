class Solution:
    def myAtoi(self, s: str) -> int:
        # Get Length
        length = len(s)
        result = 0
        negative = False
        whitespace_expected = True
        sign_expected = True

        LIMIT_L = -214748364
        LIMIT_H = 214748364

        for i in range(length):
            if ((s[i] == ' ') and (whitespace_expected == True)): # Whitespace detected and we haven't processed a digit or sign yet
                # Ignore the whitespace
                continue
            elif ((s[i] == ' ') and (whitespace_expected == False)): # Whitespace detected but we have already processed a valid symbol
                # Error: whitespace shouldn't follow a valid symbol
                break
            elif ((s[i] == '+') and (sign_expected == True)): # Positive symbol detected and we haven't encountered a digit or symbol yet
                # We shouldn't get whitespace anymore
                whitespace_expected = False

                # We shouldn't get another sign symbol anymore
                sign_expected = False

                # Resulting number will NOT be negative
                negative = False
            elif ((s[i] == '-') and (sign_expected == True)): # Negative symbol detected and we haven't encountered a digit or symbol yet
                # We shouldn't get whitespace anymore
                whitespace_expected = False

                # We shouldn't get another sign symbol anymore
                sign_expected = False

                # Resulting number will be negative
                negative = True
            elif (((s[i] == '+') or (s[i] == '-')) and (sign_expected == False)): # Sign symbol detected but we already determined the sign earlier
                # Error: Sign shouldn't be after a digit or other symbol
                break
            elif (s[i].isdigit()): # Number digit detected
                digit = ord(s[i]) - 48 # ASCII translation

                # Check if we're about to overflow
                if (((result < LIMIT_L) or ((result == LIMIT_L) and (digit < -8))) or ((result > LIMIT_H) or ((result == LIMIT_H) and (digit > 7)))):
                    return 2147483647 if (negative == False) else -2147483648
                else:
                    result = (10 * result) + digit
                
                # We shouldn't get whitespace anymore
                whitespace_expected = False

                # We shouldn't get another sign symbol anymore
                sign_expected = False
            else: # Invalid symbol
                break
        
        return result if (negative == False) else -result
        