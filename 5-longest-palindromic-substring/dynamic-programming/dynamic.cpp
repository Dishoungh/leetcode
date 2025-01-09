#include <string>

class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int start       = 0;
            int maxLength   = 1;

            int low         = -1;
            int high        = -1;

            // Traverse
            for (int i = 0; i < s.length(); i++)
            {
                // Process Odd Palindromes
                low = i;
                high = i;

                while (low >= 0 && high < s.length() && s[low] == s[high])
                {
                    int length = high - low + 1;

                    if (length > maxLength)
                    {
                        start = low;
                        maxLength = length;
                    }

                    low--;
                    high++;
                }

                // Process Even Palindromes
                low = i;
                high = i + 1;

                while (low >= 0 && high < s.length() && s[low] == s[high])
                {
                    int length = high - low + 1;

                    if (length > maxLength)
                    {
                        start = low;
                        maxLength = length;
                    }

                    low--;
                    high++;
                }
            }

            return s.substr(start, maxLength);
        }
};