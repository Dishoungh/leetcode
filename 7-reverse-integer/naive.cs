public class Solution
{
    public int Reverse(int x)
    {
        // Signed 32-bit Integer Range: [-2,147,483,648, 2,147,483,647]
        int result = 0;

        while (x != 0)
        {
            // Get current digit
            int digit = x % 10;
            x = x / 10;

            // Check to make sure result isn't overflowing
            if (((result < (Int32.MinValue / 10)) || ((result == (Int32.MinValue / 10)) && (digit < -8))) || ((result > (Int32.MaxValue / 10)) || ((result == (Int32.MaxValue / 10)) && (digit > 7))))
            {
                return 0;
            }

            // Append digit to result
            result = (10 * result) + digit;
        }

        return result; 
    }
}