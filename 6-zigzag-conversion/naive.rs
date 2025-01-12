impl Solution
{
    pub fn convert(s: String, num_rows: i32) -> String
    {
        let length: i32 = s.len() as i32;

        if (length <= 1) // If length is equal to 1, zigzag is not possible (return original string)
        {
            return s;
        }
        else if (num_rows == 1) // If numRows is equal to 1, return original string
        {
            return s;
        }
        else if (num_rows == length) // Return original string if numRows is equal to length
        {
            return s;
        }
        else
        {
            // Create new string
            let mut ans: String = String::new();

            // Traverse through rows
            for row in 0..num_rows
            {
                let mut idx: i32 = row;
                let mut down_then_up: bool = true; // This flag represents if we're going up and then down the zigzag or down and then up the zigzag

                while (idx < length)
                {
                    // Populate answer string
                    let i: usize = idx as usize;
                    let c: char = s.as_bytes()[i] as char;

                    ans.push(c);

                    if ((row == 0) || (row == (num_rows - 1))) // Zigzag Edge Logic: Next Column Index = (2 * numRows) - 2
                    {
                        idx += (2 * num_rows) - 2;
                        down_then_up = true; // Keep down_then_up flag the same
                    }
                    else if (down_then_up) // Zigzag Middle Logic: If going down then up, Next Column Index = (2 * (numRows - row) - 2)
                    {
                        idx += (2 * (num_rows - row) - 2);
                        down_then_up = false; // Now we're going up_then_down the zigzag (down = 0)
                    }
                    else // Zigzag Middle Logic: If going up then down, Next Column Index = 2 * row
                    {
                        idx += 2 * row;
                        down_then_up = true; // Now we're going down_then_up
                    }
                }
            }

            return ans;
        }
    }
}