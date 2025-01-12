class Solution 
{
    public:
        string convert(string s, int numRows)
        {
            int length = s.length();

            if (length <= 1) // If length is equal to 1, zigzag is not possible (return original string)
            {
                return s;
            }
            else if (numRows == 1) // If numRows is equal to 1, return original string
            {
                return s;
            }
            else if (numRows == length) // Return original string if numRows is equal to length
            {
                return s;
            }
            else
            {
                // Create new string
                string ans = "";

                // Traverse through rows
                int z = 0; //This keeps track of the index of the resulting zigzag string

                for (int row = 0; row < numRows; row++)
                {
                    int idx = row;
                    bool down_then_up = true; // This flag represents if we're going up and then down the zigzag or down and then up the zigzag
                    
                    while ((idx < length) && (z < length))
                    {
                        // Populate answer string
                        ans += s[idx];

                        if ((row == 0) || (row == (numRows - 1))) // Zigzag Edge Logic: Next Column Index = (2 * numRows) - 2
                        {
                            idx += (2 * numRows) - 2;
                            down_then_up = true; // Keep down_then_up flag the same
                        }
                        else if (down_then_up) // Zigzag Middle Logic: If going down then up, Next Column Index = (2 * (numRows - row) - 2)
                        {
                            idx += (2 * (numRows - row) - 2);
                            down_then_up = false; // Now we're going up_then_down the zigzag (down = 0)
                        }
                        else // Zigzag Middle Logic: If going up then down, Next Column Index = 2 * row
                        {
                            idx += 2 * row;
                            down_then_up = true; // Now we're going down_then_up
                        }
                    }

                    // If answer index is greater than or equal to length, end loop; otherwise, increment row count
                    if (z >= length)
                    {
                        break;
                    }
                }

                return ans;
            }
            
        }
};