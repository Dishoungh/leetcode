class Solution:
    def intToRoman(self, num: int) -> str:
        # Roman Numeral Maps
        THOUSANDS = ["", "M", "MM", "MMM", "",   "",  "",   "",    "",     ""]
        HUNDREDS  = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        TENS      = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ONES      = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

        return THOUSANDS[num // 1000] + HUNDREDS[(num % 1000) // 100] + TENS[(num % 100) // 10] + ONES[num % 10]
        