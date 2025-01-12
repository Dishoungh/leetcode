#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
    int m = strlen(p);
    int n = strlen(s);

    // Initialize 2D array
    //      solved[i][j] means first i characters in s match the first j characters in p
    //      Length won't be greater than 20 so matrix will be at most 441 (21 * 21) cells
    bool solved[21][21] = {false};
    
    // Empty input string and empty pattern string
    solved[0][0] = true;

    // Eliminate preceding characters with '*'
    for (int j = 1; j <= m; j++)
    {
        if ((p[j - 1] == '*') && (j > 1))
        {
            solved[0][j] = solved[0][j - 2];
        }
    }

    // Fill in the table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((p[j - 1] == '.') || (s[i - 1] == p[j - 1])) // Normal character match
            {
                solved[i][j] = solved[i - 1][j - 1];
            }
            else if ((p[j - 1] == '*') && (j >= 2))
            {
                // Check zero or more occurrence preceeding '*'
                solved[i][j] = (solved[i][j - 2] || (solved[i - 1][j] && ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.'))));
            }
            else
            {
                continue;
            }
        }
    }

    // Default return
    return solved[n][m];
}