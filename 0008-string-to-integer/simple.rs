impl Solution
{
    pub fn my_atoi(s: String) -> i32
    {
        // Get Length
        let length: usize = s.len() as usize;
        let mut result: i32 = 0;

        let mut negative: bool = false;
        let mut whitespace_expected: bool = true;
        let mut sign_expected: bool = true;

        // Constants
        const LIMIT: i32    = 214748364;
        const LIMIT_L: i32  = -2147483648;
        const LIMIT_H: i32  = 2147483647;

        for i in 0..length
        {
            let c: char = s.as_bytes()[i] as char;

            if ((c == ' ') && (whitespace_expected == true)) // Whitespace detected and we haven't processed a digit or sign yet
            {
                // Ignore the whitespace
                continue;
            }
            else if ((c == ' ') && (whitespace_expected == false)) // Whitespace detected but we have already processed a valid symbol
            {
                // Error: whitespace shouldn't follow a valid symbol
                break;
            }
            else if ((c == '+') && (sign_expected == true)) // Positive symbol detected and we haven't encountered a digit or symbol yet
            {
                // We shouldn't get whitespace anymore
                whitespace_expected = false;

                // We shouldn't get another sign symbol anymore
                sign_expected = false;

                // Resulting number will NOT be negative
                negative = false;
            }
            else if ((c == '-') && (sign_expected == true)) // Negative symbol detected and we haven't encountered a digit or symbol yet
            {
                // We shouldn't get whitespace anymore
                whitespace_expected = false;

                // We shouldn't get another sign symbol anymore
                sign_expected = false;

                // Resulting number will be negative
                negative = true;
            }
            else if (((c == '+') || (c == '-')) && (sign_expected == false)) // Sign symbol detected but we already determined the sign earlier
            {
                // Error: sign shouldn't be after a digit or other symbol
                break;
            }
            else if (c.is_digit(10)) // Number digit detected (base 10)
            {
                // ASCII translation
                let ascii: u8 = c as u8; 
                let digit: i32 = (ascii as i32) - 48;

                // Check if we're about to overflow
                let overflow_l: bool = (negative == true) && (result == LIMIT) && (digit > 8);
                let overflow_h: bool = (negative == false) && (result == LIMIT) && (digit > 7);

                if ((result > LIMIT) || (overflow_l == true) || (overflow_h == true))
                {
                    // Round to limit
                    if (negative == false)
                    {
                        return LIMIT_H;
                    }
                    else
                    {
                        return LIMIT_L;
                    }
                }
                else
                {
                    result = (10 * result) + digit;
                }

                // We shouldn't get whitespace anymore
                whitespace_expected = false;

                // We shouldn't get another sign symbol anymore
                sign_expected = false;
            }
            else // Invalid symbol
            {
                break;
            }
        }

        if (negative == true)
        {
            result *= -1;
        }

        return result;
    }
}