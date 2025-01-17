#include <stdlib.h>
#include <string.h> 

char* longestCommonPrefix(char** strs, int strsSize)
{
    if (!strsSize)
    {
        return "";
    }
    else
    {
        for (int j = 0; j < strlen(strs[0]); j++)
        {
            for (int i = 1; i < strsSize; i++)
            {
                if (strs[i][j] != strs[0][j]) //Prefix no longer matches
                {
                    // Cut off first string
                    strs[0][j] = '\0';

                    // Return first string
                    return strs[0];
                }
            }
        }

        // Default return
        return strs[0];
    }
}