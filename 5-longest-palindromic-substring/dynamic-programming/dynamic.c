#include <stdlib.h>
#include <string.h>  

char* longestPalindrome(char* s)
{
    int start       = 0;
    int maxLength   = 1;

    int low         = -1;
    int high        = -1;
    int N           = strlen(s);

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

    // Generate Substring
    char* sub = (char*)(malloc((maxLength + 1) * sizeof(char)));
    strncpy(sub, (s + start), maxLength);
    sub[maxLength] = '\0';
    return sub;
}