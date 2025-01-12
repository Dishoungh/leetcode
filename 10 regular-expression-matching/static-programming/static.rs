impl Solution
{
    pub fn is_match_helper(s: String, p: String, a: usize, b: usize) -> bool
    {
        // If pattern is empty, input string must also be empty
        if (b == 0)
        {
            return (a == 0);
        }

        let c: char = p.as_bytes()[b - 1] as char;

        // If input string is empty, pattern must have characters followed by "*"
        if (a == 0)
        {
            // Check if pattern string is at least 2 and has a "*" at the end. If so, then return isMatchHelper(s, p, a, b - 2)
            if (b >= 2)
            {
                return ((c == '*') && Self::is_match_helper(s.clone(), p.clone(), a, b - 2));
            }
            else
            {
                return false;
            }
        }

        let d: char = s.as_bytes()[a - 1] as char;

        // If last character of both input and pattern strings match or has '.'
        if ((c == d) || (c == '.'))
        {
            return Self::is_match_helper(s.clone(), p.clone(), a - 1, b - 1);
        }

        // If there is a '*' in the pattern
        if ((c == '*') && (b >= 2))
        {
            // Check if the preceding character zero or more times
            let e: char = p.as_bytes()[b - 2] as char;
            return ((Self::is_match_helper(s.clone(), p.clone(), a, b - 2)) || (((d == e) || (e == '.')) && Self::is_match_helper(s.clone(), p.clone(), a - 1, b)));
        }

        // Default return
        return false;
    }

    pub fn is_match(s: String, p: String) -> bool
    {
        let a: usize = s.len() as usize;
        let b: usize = p.len() as usize;

        return Self::is_match_helper(s.clone(), p.clone(), a, b);
    }
}