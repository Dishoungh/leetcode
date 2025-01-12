public class Solution
{
    public bool IsPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else
        {
            int original = x;
            int reversed = 0;

            // Store digits in reverse order in "reversed"
            while (x != 0)
            {
                int digit = x % 10;

                // Check if we're going to overflow
                if ((reversed > (Int32.MaxValue / 10)) || ((reversed == (Int32.MaxValue / 10)) && (digit > 7)))
                {
                    return false;
                }
                else
                {
                    reversed = (10 * reversed) + digit;
                    x /= 10;
                }
            }
            
            return (original == reversed);
        }
    }
}