#include <string>

class Solution
{
    public:
        string longestCommonPrefix(vector<string>& strs)
        {
            if (strs.empty())
            {
                return "";
            }
            else
            {
                for (int j = 0; j < strs[0].length(); j++)
                {
                    for (int i = 1; i < strs.size(); i++)
                    {
                        if (strs[i][j] != strs[0][j]) // Prefix no longer matches
                        {
                            // Return substring
                            return strs[0].substr(0, j);
                        }
                    }
                }
            }

            // Default return
            return strs[0];
        }
};