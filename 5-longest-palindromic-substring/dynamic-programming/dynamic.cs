public class Solution
{
    public string LongestPalindrome(string s)
    {
        int start       = 0;
        int maxLength   = 1;

        int low         = -1;
        int high        = -1;
        int N           = s.Length;

        // Traverse
        for (int i = 0; i < N; i++)
        {
            // Process Odd Palindromes
            low = i;
            high = i;

            while (low >= 0 && high < N && s[low] == s[high])
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

            while (low >= 0 && high < N && s[low] == s[high])
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

        return s.Substring(start, maxLength);
    }
}