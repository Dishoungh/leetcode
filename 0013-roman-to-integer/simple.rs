impl Solution
{
    pub fn get_roman_value(c: char) -> i32
    {
        match c
        {
            'M' => return 1000,
            'D' => return 500,
            'C' => return 100,
            'L' => return 50,
            'X' => return 10,
            'V' => return 5,
            'I' => return 1,
            _   => return 0,
        }
    }

    pub fn roman_to_int(s: String) -> i32
    {
        let length: usize = s.len() as usize;
        let mut previous: i32 = 0;
        let mut result: i32 = 0;

        for i in 0..length
        {
            //let c: char = s.as_bytes()[i] as char;
            let current: i32 = Self::get_roman_value(s.chars().nth(i).unwrap());

            // Add to result
            result += current;

            if (current > previous) // Subtract result from previous in special cases
            {
                result -= (2 * previous);
            }

            // Update previous
            previous = current;
        }

        return result;
    }
}