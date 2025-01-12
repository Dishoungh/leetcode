impl Solution
{
    pub fn is_palindrome(x: i32) -> bool
    {
        if (x < 0)
        {
            return false;
        }
        else
        {
            let original: i32 = x;
            let mut n: i32 = x;
            let mut reversed: i32 = 0;

            const LIMIT: i32 = 214748364;

            // Store digits in reverse order in "reversed"
            while (n != 0)
            {
                let digit: i32 = n % 10;

                // Check for overflow
                if ((reversed > LIMIT) || ((reversed == LIMIT) && (digit > 7)))
                {
                    return false;
                }
                else
                {
                    reversed = (10 * reversed) + digit;
                    n = n / 10;
                }
            }

            return (original == reversed);
        }
    }
}