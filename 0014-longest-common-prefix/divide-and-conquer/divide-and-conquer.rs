use std::cmp;

impl Solution
{
    pub fn find_common_prefix(s1: String, s2: String) -> String
    {
        let s1_length: usize = s1.len() as usize;
        let s2_length: usize = s2.len() as usize;
        let min_length: usize = cmp::min(s1_length, s2_length) as usize;

        for i in 0..min_length
        {
            let c: char = s1.as_bytes()[i] as char;
            let d: char = s2.as_bytes()[i] as char;

            if (c != d)
            {
                // Cut off base string
                return &s1[0..i].to_string();
            }
        }

        // Default return
        if (s1_length <= s2_length)
        {
            return s1;
        }
        else
        {
            return s2;
        }
    }

    pub fn divide_and_conquer(strs: Vec<String>, left: u8, right: u8) -> String
    {
        // Boundary check
        if (left == right)
        {
            let i: usize = left as u8;
            return strs[left];
        }
        else
        {
            let middle: u8 = (left + right) / 2;
            String ls = Self::divide_and_conquer(strs, left, middle);
            String rs = Self::divide_and_conquer(strs, (middle + 1), right);
            return Self::find_common_prefix(ls, rs);
        }
    }

    pub fn longest_common_prefix(strs: Vec<String>) -> String
    {
        let size: usize = strs.len() as usize;
        if (size == 0)
        {
            return "".to_string();
        }
        else
        {
            return Self::divide(strs, 0, strs.len() - 1);
        }
    }
}