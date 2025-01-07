public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int max = 0;

        for (int i = 0; i < s.Length; i++)
        {
            int[] count = new int[128];

            for (int j = i; j < s.Length; j++)
            {
                if (count[s[j]] != 0)
                {
                    break;
                }
                else
                {
                    max = Math.Max(max, (j - i + 1));
                    count[s[j]] = 1;
                }
            }
        }

        return max;
    }
}