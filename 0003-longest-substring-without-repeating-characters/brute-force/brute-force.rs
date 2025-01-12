use std::cmp;

impl Solution
{
    pub fn length_of_longest_substring(s: String) -> i32
    {
        let mut i: i32 = 0;
        let mut maxLen: i32 = 0;
        let length: i32 = s.len() as i32;

        while (i < length)
        {
            // Initialize array with 128 zeros (128 ASCII total characters)
            let mut visited: [i32; 128] = [0; 128];

            let mut j: i32 = i;

            while (j < length)
            {
                let mut idx: usize = j as usize;
                let code: u8 = s.as_bytes()[idx];
                idx = code as usize;

                if (visited[idx] != 0)
                {
                    break;
                }
                else
                {
                    maxLen = cmp::max(maxLen, (j - i + 1));
                    visited[idx] = 1;
                }

                j += 1;
            }

            i += 1;
        }

        return maxLen;
    }
}