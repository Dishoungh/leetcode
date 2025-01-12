public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int max = 0;
        int[] visited = new int[128];

        int left = 0;
        int right = 0;

        while (right < s.Length)
        {
            if (visited[s[right]] == 0)
            {
                visited[s[right]] = 1;
                right++;
                max = Math.Max(max, (right - left));
            }
            else
            {
                visited[s[left]] = 0;
                left++;
            }
        }

        return max;
    }
}