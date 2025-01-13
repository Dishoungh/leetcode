#include <string>
#include <vector>

class Solution
{
    public:
        string intToRoman(int num)
        {
            // Roman Numeral Maps
            const vector<string> THOUSANDS{"", "M", "MM", "MMM", "",   "",  "",   "",    "",     ""};
            const vector<string>  HUNDREDS{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
            const vector<string>      TENS{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
            const vector<string>      ONES{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

            return THOUSANDS[num / 1000] + HUNDREDS[(num % 1000) / 100] + TENS[(num % 100) / 10] + ONES[num % 10];
        }
};