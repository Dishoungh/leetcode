impl Solution
{
    pub fn is_match(s: String, p: String) -> bool
    {
        let m: usize = p.len() as usize;
        let n: usize = s.len() as usize;

        // Initialize 2D array
        //      solved[i][j] means first i characters in s match the first j characters in p
        //      Length won't be greater than 20 so matrix will be at most 441 (21 * 21) cells
        let mut solved: [[bool; 21]; 21] = [[false; 21]; 21];

        // Empty input string and empty pattern string
        solved[0][0] = true;

        // Eliminate preceding characters with '*'
        for j in 1..=m
        {
            let c: char = p.as_bytes()[j - 1] as char;
            if ((c == '*') && (j > 1))
            {
                solved[0][j] = solved[0][j - 2];
            }
        }

        // Fill in the table
        for i in 1..=n
        {
            for j in 1..=m
            {
                let c: char = s.as_bytes()[i - 1] as char;
                let d: char = p.as_bytes()[j - 1] as char;

                if ((d == '.') || (c == d)) // Normal character match
                {
                    solved[i][j] = solved[i - 1][j - 1];
                }
                else if ((d == '*') && (j >= 2))
                {
                    // Check zero or more occurrence preceeding '*'
                    let e: char = p.as_bytes()[j - 2] as char;
                    solved[i][j] = (solved[i][j - 2] || (solved[i - 1][j] && ((c == e) || (e == '.'))));
                }
                else
                {
                    continue;
                }
            }
        }
        
        return solved[n][m];
    }
}