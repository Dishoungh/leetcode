#include <string.h> 

char* findCommonPrefix(char* s1, char* s2)
{
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);

    for (int i = 0; i < ((s1_length <= s2_length) ? s1_length : s2_length); i++)
    {
        if (s1[i] != s2[i])
        {
            // Cut off base string (s1)
            s1[i] = '\0';
            return s1;
        }
    }

    // Default return
    return ((s1_length <= s2_length) ? s1 : s2);
}

char* divide(char** strs, int left, int right)
{
    // Boundary check
    if (left == right)
    {
        return strs[left];
    }
    else
    {
        int middle = (left + right) / 2;
        char* ls = divide(strs, left, middle);
        char* rs = divide(strs, (middle + 1), right);
        return findCommonPrefix(ls, rs);
    }
}

char* longestCommonPrefix(char** strs, int strsSize)
{
    if (!strsSize)
    {
        return "";
    }
    else
    {
        
        return divide(strs, 0, strsSize - 1);
    }
}