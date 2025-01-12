impl Solution
{
    pub fn reverse(x: i32) -> i32
    {
        // Signed 32-bit Integer Range: [-2,147,483,648, 2,147,483,647]
        let mut num: i32 = x;
        let mut result: i32 = 0;
        const LIMIT_L: i32 = -214748364;
        const LIMIT_H: i32 = 214748364;

        while (num != 0)
        {
            // Get current digit
            let digit: i32 = num % 10;
            num = (num / 10) as i32;

            // Check to make sure result isn't overflowing
            if (((result < LIMIT_L) || ((result == LIMIT_L) && (digit < -8))) || ((result > LIMIT_H) || ((result == LIMIT_H) && (digit > 7))))
            {
                return 0;
            }

            // Append digit to result
            result = (10 * result) + digit;
        }

        return result; 
    }
}