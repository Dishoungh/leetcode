impl Solution
{
    pub fn int_to_roman(num: i32) -> String
    {
        // Roman Numeral String
        let mut roman: String = String::new();

        // Check Thousands
        let thousands: u8 = (num / 1000) as u8;
        match thousands
        {
            1 => roman.push_str("M"),
            2 => roman.push_str("MM"),
            3 => roman.push_str("MMM"),
            _ => roman.push_str(""),
        }

        // Check Hundreds
        let hundreds: u8 = ((num % 1000) / 100) as u8;
        match hundreds
        {
            1 => roman.push_str("C"),
            2 => roman.push_str("CC"),
            3 => roman.push_str("CCC"),
            4 => roman.push_str("CD"),
            5 => roman.push_str("D"),
            6 => roman.push_str("DC"),
            7 => roman.push_str("DCC"),
            8 => roman.push_str("DCCC"),
            9 => roman.push_str("CM"),
            _ => roman.push_str(""),
        }

        // Check Tens
        let tens: u8 = ((num % 100) / 10) as u8;
        match tens
        {
            1 => roman.push_str("X"),
            2 => roman.push_str("XX"),
            3 => roman.push_str("XXX"),
            4 => roman.push_str("XL"),
            5 => roman.push_str("L"),
            6 => roman.push_str("LX"),
            7 => roman.push_str("LXX"),
            8 => roman.push_str("LXXX"),
            9 => roman.push_str("XC"),
            _ => roman.push_str(""),
        }

        // Check Ones
        let hundreds: u8 = (num % 10) as u8;
        match hundreds
        {
            1 => roman.push_str("I"),
            2 => roman.push_str("II"),
            3 => roman.push_str("III"),
            4 => roman.push_str("IV"),
            5 => roman.push_str("V"),
            6 => roman.push_str("VI"),
            7 => roman.push_str("VII"),
            8 => roman.push_str("VIII"),
            9 => roman.push_str("IX"),
            _ => roman.push_str(""),
        }

        return roman;
    }
}