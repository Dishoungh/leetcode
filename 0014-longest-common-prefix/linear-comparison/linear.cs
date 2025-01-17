public class Solution
{
    public string LongestCommonPrefix(string[] strs)
    {
        if (strs.Length == 0)
        {
            return "";
        }
        else
        {
            for (int j = 0; j < strs[0].Length; j++)
            {
                for (int i = 1; i < strs.Length; i++)
                {
                    if ((j == strs[i].Length) || (strs[i][j] != strs[0][j]))  //Prefix no longer matches
                    {
                        // Return substring
                        return strs[0].Substring(0, j);
                    }
                }
            }

            // Default return
            return strs[0];
        }
    }
}