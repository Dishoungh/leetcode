#include <limits>

using namespace std;

class Solution
{
    public:
        int isdigit(char c)
        {
            if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9'))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int myAtoi(string s)
        {
            // Get length
            int length = s.length();
            int result = 0;
            bool negative = false;
            bool whitespace_expected = true;
            bool sign_expected = true;

            for (int i = 0; i < length; i++)
            {
                if ((s[i] == ' ') && whitespace_expected) // Whitespace detected and we haven't processed a digit or sign yet 
                {
                    // Ignore the whitespace
                    continue;
                }
                else if ((s[i] == ' ') && !whitespace_expected) // Whitespace detected but we've already processed a digit or sign
                {
                    // Error: whitespace shouldn't be after a character
                    break;
                }
                else if ((s[i] == '+') && sign_expected) // Positive symbol detected and we haven't encountered a digit or symbol yet
                {
                    // We shouldn't get whitespace anymore
                    whitespace_expected = false;

                    // We shouldn't get another sign symbol anymore
                    sign_expected = false;

                    // Resulting number will NOT be negative
                    negative = false;
                }
                else if ((s[i] == '-') && sign_expected) // Negative symbol detected and we haven't encountered a digit or symbol yet
                {
                    // We shouldn't get whitespace anymore
                    whitespace_expected = false;

                    // We shouldn't get another sign symbol anymore
                    sign_expected = false;

                    // Resulting number will be negative
                    negative = true;
                }
                else if (((s[i] == '+') || (s[i] == '-')) && !sign_expected) // Sign symbol detected but we already determined the sign earlier
                {
                    // Error: Sign shouldn't be after a digit or other symbol
                    break;
                }
                else if (isdigit(s[i])) // Number digit detected
                {
                    // Append digit to result
                    int digit = (int)(s[i]) - 48; // ASCII translation

                    // Check if we're about to overflow
                    if (((result < (INT_MIN / 10)) || ((result == (INT_MIN / 10)) && (digit < -8))) || ((result > (INT_MAX / 10)) || ((result == (INT_MAX / 10)) && (digit > 7))))
                    {
                        return negative ? INT_MIN : INT_MAX;
                    }
                    else
                    {
                        result = (10 * result) + digit;
                    }

                    // We shouldn't get whitespace anymore
                    whitespace_expected = false;

                    // We shouldn't get another sign symbol anymore
                    sign_expected = false;
                }
                else // Invalid symbol
                {
                    break;
                }
            }

            return negative ? -result : result;
        }
};