class Solution
{
    public:

        int lengthOfLongestSubstring(string s)
        {
            int len = s.length();
            int max = 0;

            for (int i = 0; i < len; i++)
            {
                int count[128] = {0};

                for (int j = i; j < len; j++)
                {
                    if (count[s[j]])
                    {
                        break;
                    }
                    else
                    {
                        max = std::max(max, (j - i + 1));
                        count[s[j]] = 1;
                    }
                }
            }

            return max;
        }
};