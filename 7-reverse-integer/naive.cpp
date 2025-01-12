#include <limits>
class Solution
{
    public:
        int reverse(int x)
        {
            // Signed 32-bit Integer Range: [-2,147,483,648, 2,147,483,647]
            int result = 0;

            while (x)
            {
                // Get current digit
                int digit = x % 10;
                x = x / 10;

                // Check to make sure result isn't overflowing
                if (((result < (INT_MIN / 10)) || ((result == (INT_MIN / 10)) && (digit < -8))) || ((result > (INT_MAX / 10)) || ((result == (INT_MAX / 10)) && (digit > 7))))
                {
                    return 0;
                }

                // Append digit to result
                result = (10 * result) + digit;
            }

            return result;
        }
};