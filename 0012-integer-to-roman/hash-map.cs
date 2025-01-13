public class Solution
{
    public string IntToRoman(int num)
    {
        // Roman Numeral Maps
        string[] THOUSANDS = new string[10] {"", "M", "MM", "MMM", "",   "",  "",   "",    "",     ""};
        string[]  HUNDREDS = new string[10] {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string[]      TENS = new string[10] {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string[]      ONES = new string[10] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return THOUSANDS[num / 1000] + HUNDREDS[(num % 1000) / 100] + TENS[(num % 100) / 10] + ONES[num % 10];
    }
}