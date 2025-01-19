#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(int idx, const char* digits, const char** map, char* tmp, int depth, char*** res, int* returnSize)
{
    if (depth == strlen(digits))
    {
        (*res)[*returnSize] = strdup(tmp);
        (*returnSize)++;
        return;
    }
    else
    {
        // Capture combination for result[i]
        for (; idx < strlen(digits); idx++)
        {
            int i = digits[idx] - '0';
            for (int j = 0; map[i][j] != '\0'; j++)
            {
                tmp[depth] = map[i][j];
                dfs(idx + 1, digits, map, tmp, depth + 1, res, returnSize);
            }
        }
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    int length = strlen(digits);
    *returnSize = 0;

    if (!length)
    {
        return NULL;
    }
    else
    {
        //Letters Map             0   1    2      3      4      5      6      7       8      9
        const char* letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // Total array list
        char** result = (char**) malloc(256 * sizeof(char*));
        char* tmp = (char*) malloc((strlen(digits) + 1) * sizeof(char));
        tmp[strlen(digits)] = 0;

        // Search for combinations
        dfs(0, digits, letters, tmp, 0, &result, returnSize);
        
        // Return
        free(tmp);
        return result;
    }
}