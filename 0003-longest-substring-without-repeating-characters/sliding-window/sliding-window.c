#include <stdint.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int length = strlen(s);
    int max = 0;

    uint16_t count[128] = {0}; // 128 ASCII Characters Total

    uint16_t a = 0; // Left pointer
    uint16_t b = 0; // Right pointer

    while (b < length)
    {
        if (!count[s[b]])
        {
            count[s[b]] = 1;
            b++;
            max = (max > (b - a)) ? max : (b - a);
        }
        else
        {
            count[s[a]] = 0;
            a++;
        }
    }

    return max;
}