#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int length = strlen(s);
    int max    = 0;

    for (int i = 0; i < length; i++)
    {
        int count[128] = {0};

        for (int j = i; j < length; j++)
        {
            if (count[s[j]])
            {
                break;
            }
            else
            {
                int tmp = j - i + 1;
                if (tmp > max)
                {
                    max = tmp;
                }
                
                count[s[j]] = 1;
            }
        }
    }
    return max;
}