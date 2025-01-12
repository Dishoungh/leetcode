impl Solution 
{
    pub fn longest_palindrome(s: String) -> String
    {
        let mut start: usize = 0;
        let mut maxLength: usize = 1;

        let N: usize = s.len() as usize;
        let mut arr: [[bool; 1000]; 1000] = [[false; 1000]; 1000];

        // Initialize Array
        for i in 0..N
        {
            arr[i][i] = true;
        }

        // Check Matching Substrings of Length 2
        for i in 0..(N-1)
        {
            let a: char = s.as_bytes()[i] as char;
            let b: char = s.as_bytes()[i + 1] as char;
            if (a == b)
            {
                arr[i][i + 1] = true;
                start = i; 
                maxLength = 2;
            }
        }

        // Traverse
        for i in 3..(N+1)
        {
            for j in 0..(N-i+1)
            {
                let k: usize = i + j - 1;

                let a: char = s.as_bytes()[j] as char;
                let b: char = s.as_bytes()[k] as char;
                if ((arr[j + 1][k - 1]) && (a == b))
                {
                    arr[j][k] = true;

                    if (i > maxLength)
                    {
                        start = j;
                        maxLength = i;
                    }
                }
            }
        }

        return s;
    }
}