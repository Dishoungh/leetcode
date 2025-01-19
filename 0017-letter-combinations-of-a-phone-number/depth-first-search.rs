impl Solution
{
    pub fn depth_first_search(index: usize, digits: &String, map: &[&str; 8], tmp: &mut String, res: &mut Vec<String>)
    {
        if (index == digits.len())
        {
            res.push(tmp.clone());
            return;
        }
        else
        {
            // Build combination
            let numsString = map[((digits.chars().nth(index).unwrap() as u8) - b'2') as usize];

            for c in numsString.chars()
            {
                tmp.push(c);
                Self::depth_first_search(index + 1, digits, map, tmp, res);
                tmp.pop();
            }
        }
    }

    pub fn letter_combinations(digits: String) -> Vec<String>
    {
        let mut result: Vec<String> = Vec::new();
        let letters: [&str; 8] = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];

        if (digits.len() != 0)
        {
            let mut tree: String = String::new();
            Self::depth_first_search(0, &digits, &letters, &mut tree, &mut result);
        }

        return result;
    }
}