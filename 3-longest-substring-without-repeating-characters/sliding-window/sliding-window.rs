use std::cmp;

impl Solution
{
    pub fn length_of_longest_substring(s: String) -> i32
    {
        let mut maxLen: i32 = 0;
        let length: i32 = s.len() as i32;

        // Initialize array with 128 zeros (128 ASCII total characters)
        let mut visited: [i32; 128] = [0; 128];

        let mut a: i32 = 0;
        let mut b: i32 = 0;

        while (b < length)
        {
            let tmp: usize = b as usize;
            let code: u8 = s.as_bytes()[tmp];
            let idx: usize = code as usize;

            if (visited[idx] == 0)
            {
                visited[idx] = 1;
                b += 1;
                maxLen = cmp::max(maxLen, (b - a));
            }
            else
            {
                let tmp2: usize = a as usize;
                let code2: u8 = s.as_bytes()[tmp2];
                let idx2: usize = code2 as usize;

                visited[idx2] = 0;
                a += 1;
            }
        }

        return maxLen;
    }
}