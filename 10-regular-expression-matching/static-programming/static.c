#include <stdbool.h>
#include <string.h>

// Helper function for isMatch (a = length of input string | b = length of pattern string)
bool isMatchHelper(char* s, char* p, int a, int b)
{
    // If pattern is empty, input string must also be empty
    if (!b)
    {
        return (!a);
    }

    // If input string is empty, pattern must have characters followed by "*"
    if (!a)
    {
        // Check if pattern string is at least 2 and has a "*" at the end. If so, then return isMatchHelper(s, p, a, b - 2)
        return ((b >= 2) && (p[b - 1] == '*') && isMatchHelper(s, p, a, b - 2));
    }

    // If last character of both input and pattern strings match or has '.'
    if ((s[a - 1] == p[b - 1]) || (p[b - 1] == '.'))
    {
        return isMatchHelper(s, p, a - 1, b - 1);
    }

    // If there is a '*' in the pattern
    if ((p[b - 1] == '*') && (b >= 2))
    {
        // Check if the preceding character zero or more times
        return ((isMatchHelper(s, p, a, b - 2)) || (((s[a - 1] == p[b - 2]) || (p[b - 2] == '.')) && isMatchHelper(s, p, a - 1, b)));
    }

    // Default return
    return false;
} 

bool isMatch(char* s, char* p)
{
    return isMatchHelper(s, p, strlen(s), strlen(p));
}