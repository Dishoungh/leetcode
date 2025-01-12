public class Solution
{
    public string LongestPalindrome(string s)
    {
        if (s.Length == 1)
        {
            return s;
        }

        int N = 2 * s.Length + 1;

        // LPS Array
        int[] LPS = new int[N];
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

            if (expand == 1)
            {
                //Expand palindrom centered at i
                while (true)
                {
                    int u = (int)((i + LPS[i] + 1) / 2);
                    int v = (int)((i - LPS[i] - 1) / 2);

                    if (u >= s.Length)
                    {
                        break;
                    }
                    else if (v <= 0)
                    {
                        break;
                    }
                    else if (((i + LPS[i] + 1) % 2 != 0) && (s[u] != s[v]))
                    {
                        break;
                    }
                    else
                    {
                        LPS[i]++;
                    }
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

        int start = (maxLPSPosition - maxLPSLength) / 2;
        return s.Substring(start, maxLPSLength);
    }
}