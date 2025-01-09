#include <string>

class Solution
{
    public:
        string longestPalindrome(string s)
        {
            if (s.length() == 1)
            {
                return s;
            }
            
            int N = 2 * s.length() + 1;

            // LPS Array
            int LPS[N];
            LPS[0] = 0;
            LPS[1] = 1;

            int l = 0; // Current Left Position
            int c = 1; // Center Position
            int r = 2; // Center Right Position

            // Other Variables
            int expand = -1;
            int diff = -1;
            int maxLPSLength = 0;
            int maxLPSPosition = 0;
            int start = -1;
            
            for (int i = 2; i < N; i++)
            {
                // Get Current Left Position
                l = 2 * c - i;

                // Reset expand
                expand = 0;

                // If current right position is within center right
                diff = r - i;
                if (diff >= 0)
                {
                    if (LPS[l] < diff)
                    {
                        LPS[i] = LPS[l];
                    }
                    else if ((LPS[l] == diff) && (r == (N - 1)))
                    {
                        LPS[i] = LPS[l];
                    }
                    else if ((LPS[l] == diff) && (r < (N - 1)))
                    {
                        LPS[i] = LPS[l];

                        //expansion require
                        expand = 1;
                    }
                    else if (LPS[l] > diff)
                    {
                        LPS[i] = diff;

                        //epxnaion required
                        expand = 1;
                    }
                }
                else
                {
                    LPS[i] = 0;

                    //expansion required
                    expand = 1;
                }

                if (expand)
                {
                    //Expand palindrom centered at i
                    while (((i + LPS[i]) < N && (i - LPS[i]) > 0) && (((i + LPS[i] + 1) % 2 == 0) || (s[(i + LPS[i] + 1) / 2] == s[(i - LPS[i] - 1) / 2])))
                    {
                        LPS[i]++;
                    }
                }

                // Update max LPS length
                if (LPS[i] > maxLPSLength)
                {
                    maxLPSLength = LPS[i];
                    maxLPSPosition = i;
                }

                // Update center and right positions
                if (i + LPS[i] > r)
                {
                    c = i;
                    r = i + LPS[i];
                }
            }

            start = (maxLPSPosition - maxLPSLength) / 2;

            return s.substr(start, maxLPSLength);
        }
};