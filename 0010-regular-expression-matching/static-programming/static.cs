public class Solution
{
    public bool isMatchHelper(string s, string p, int a, int b)
    {
        // If pattern is empty, input string must also be empty
        if (b == 0)
        {
            return (a == 0);
        }

        // If input string is empty, pattern must have characters followed by "*"
        if (a == 0)
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

    public bool IsMatch(string s, string p)
    {
        return isMatchHelper(s, p, s.Length, p.Length);
    }
}