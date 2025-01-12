use std::cmp;

impl Solution
{
    pub fn longest_palindrome(s: String) -> String
    {
        if (s.len() == 1)
        {
            return s;
        }
        
        let N: usize = 2 * s.len() + 1;
        let mut LPS: [i32; 2005] = [0; 2005];
        LPS[0] = 0;
        LPS[1] = 1;

        let mut l: i32 = 0; // Current Left Position
        let mut c: i32 = 1; // Center Position
        let mut r: i32 = 2; // Center Right Position

        // Other Variables
        let mut maxLPSLength: i32 = 0;
        let mut maxLPSPosition: i32 = 0;

        for i in 2..N
        {
            // Get Current Left Position
            l = 2 * c - l;

            let expand: bool = false;

            // If current right position is within center right
            let j: i32 = i as i32;
            let k: usize = l as usize;
            let q: i32 = N as i32;

            let diff: i32 = r - j;
            if (diff >= 0)
            {
                if (LPS[k] < diff)
                {
                    LPS[i] = LPS[k];
                }
                else if ((LPS[k] == diff) && (r == (q - 1)))
                {
                    LPS[i] = LPS[k];
                }
                else if ((LPS[k] == diff) && (r < (q - 1)))
                {
                    LPS[i] = LPS[k];

                    //expansion required
                    expand = true;
                }
                else
                {
                    LPS[i] = diff;

                    //epxnaion required
                    expand = true;
                }
            }
            else
            {
                LPS[i] = 0;
                expand = true;
            }

            if (expand)
            {
                // Expand palindrome centered at i
                while (true)
                {
                    let u: usize = ((j + LPS[i] + 1) / 2) as usize;
                    let v: usize = ((j - LPS[i] - 1) / 2) as usize;

                    if (u >= s.len())
                    {
                        break;
                    }
                    else if (v <= 0)
                    {
                        break;
                    }
                    else if (((j + LPS[i] + 1) % 2 != 0) && (s[u] != s[v]))
                    {
                        break;
                    }
                    else
                    {
                        LPS[i] += 1;
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

        return s;
    }
}