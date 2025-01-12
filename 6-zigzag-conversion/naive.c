#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    uint16_t length = (uint16_t) strlen(s);

    if (length <= 1) // If length is equal to 1, zigzag is not possible (return original string)
    {
        return s;
    }
    else if (numRows == 1) // If numRows is equal to 1, return original string
    {
        return s;
    }
    else if (numRows == (int)length) // Return original string if numRows is equal to length
    {
        return s;
    }
    else
    {
        // Create new string
        char* ans = (char*) malloc((length + 1) * sizeof(char));

        // Traverse through rows
        uint16_t z = 0; //This keeps track of the index of the resulting zigzag string

        for (uint16_t row = 0; row < (uint16_t) numRows; row++)
        {
            uint16_t idx = row;
            uint8_t down_then_up = 1; // This flag represents if we're going up and then down the zigzag or down and then up the zigzag
            
            while ((idx < length) && (z < length))
            {
                // Populate answer string
                ans[z++] = s[idx];

                if ((row == 0) || (row == ((uint16_t) numRows) - 1)) // Zigzag Edge Logic: Next Column Index = (2 * numRows) - 2
                {
                    idx += (2 * (uint16_t) numRows) - 2;
                    down_then_up = 1; // Keep down_then_up flag the same
                }
                else if (down_then_up) // Zigzag Middle Logic: If going down then up, Next Column Index = (2 * (numRows - row) - 2)
                {
                    idx += (2 * ((uint16_t) numRows - row) - 2);
                    down_then_up = 0; // Now we're going up_then_down the zigzag (down = 0)
                }
                else // Zigzag Middle Logic: If going up then down, Next Column Index = 2 * row
                {
                    idx += 2 * row;
                    down_then_up = 1; // Now we're going down_then_up
                }
            }

            // If answer index is greater than or equal to length, end loop; otherwise, increment row count
            if (z >= length)
            {
                break;
            }
        }

        // Append NULL character at the end of answer string
        ans[length] = '\0';

        return ans;
    }
}