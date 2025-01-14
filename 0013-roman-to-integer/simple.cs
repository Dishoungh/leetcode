public class Solution
{
    public int getValue(char c)
    {
        switch (c)
        {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
            default: return 0;
        }
    }

    public int RomanToInt(string s)
    {
        int length   = s.Length;
        int previous = 0;
        int result   = 0;

        for (int i = 0; i < length; i++)
        {
            int current = getValue(s[i]);
            
            // Add to result
            result += current;

            if (current > previous) // Subtract result from previous value for cases like IV = 5 - 1 = 4, IX = 10 - 1 = 9, XL = 50 - 10 = 40, etc 
            {
                result -= (2 *previous);
            }
            
            // Update previous
            previous = current;
        }

        return result;  
    }
}