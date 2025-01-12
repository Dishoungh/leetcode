class Solution
{
    public:

        int lengthOfLongestSubstring(string s)
        {
            int len = s.length();
            int max = 0;

            int visited[128] = {0};

            int left = 0;
            int right = 0;

            while (right < len)
            {
                if (!visited[s[right]])
                {
                    visited[s[right]] = 1;
                    right++;
                    max = std::max(max, (right - left));
                }
                else
                {
                    visited[s[left]] = 0;
                    left++;
                }
            }

            return max;
        }
};