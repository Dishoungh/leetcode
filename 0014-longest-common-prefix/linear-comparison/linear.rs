impl Solution
{
    pub fn longest_common_prefix(strs: Vec<String>) -> String
    {
        let size: usize = strs.len() as usize;
        if (size == 0)
        {
            return "".to_string();
        }
        else
        {
            let length: usize = strs[0].len() as usize;
            for j in 0..length
            {
                for i in 1..size
                {
                    

                    if (j == length) // Edge case
                    {
                        // Return substring
                        let s: String = strs[0].clone();
                        let sub: &str = &s[0..j];
                        return sub.to_string();
                    }

                    let c: char = strs[0].as_bytes()[j] as char;
                    let d: char = strs[i].as_bytes()[j] as char;

                    if (c != d) // Prefix no longer matches
                    {
                        // Return substring
                        let s: String = strs[0].clone();
                        let sub: &str = &s[0..j];
                        return sub.to_string();
                    }
                }
            }

            // Default return
            return strs[0].clone();
        }
    }
}