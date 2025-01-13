#include <stdlib.h>
#include <string.h>

char* intToRoman(int num)
{
    // Roman Numeral String (Max Size = 16)
    char* roman = (char*) calloc(16, sizeof(char));
    
    if (!roman)
    {
        return NULL;
    }
    
    // Check thousands
    switch (num / 1000)
    {
        case 1:
            strncat(roman, "M", 1);
            break;
        case 2:
            strncat(roman, "MM", 2);
            break;
        case 3:
            strncat(roman, "MMM", 3);
            break;
        default:
            break;
    }
    
    // Check hundreds
    switch ((num % 1000) / 100)
    {
        case 1:
            strncat(roman, "C", 1);
            break;
        case 2:
            strncat(roman, "CC", 2);
            break;
        case 3:
            strncat(roman, "CCC", 3);
            break;
        case 4:
            strncat(roman, "CD", 2);
            break;
        case 5:
            strncat(roman, "D", 1);
            break;
        case 6:
            strncat(roman, "DC", 2);
            break;
        case 7:
            strncat(roman, "DCC", 3);
            break;
        case 8:
            strncat(roman, "DCCC", 4);
            break;
        case 9:
            strncat(roman, "CM", 2);
            break;
        default:
            break;
    }
    
    // Check tens
    switch ((num % 100) / 10)
    {
        case 1:
            strncat(roman, "X", 1);
            break;
        case 2:
            strncat(roman, "XX", 2);
            break;
        case 3:
            strncat(roman, "XXX", 3);
            break;
        case 4:
            strncat(roman, "XL", 2);
            break;
        case 5:
            strncat(roman, "L", 1);
            break;
        case 6:
            strncat(roman, "LX", 2);
            break;
        case 7:
            strncat(roman, "LXX", 3);
            break;
        case 8:
            strncat(roman, "LXXX", 4);
            break;
        case 9:
            strncat(roman, "XC", 2);
            break;
        default:
            break;
    }
    
    // Check ones
    switch (num % 10)
    {
        case 1:
            strncat(roman, "I", 1);
            break;
        case 2:
            strncat(roman, "II", 2);
            break;
        case 3:
            strncat(roman, "III", 3);
            break;
        case 4:
            strncat(roman, "IV", 2);
            break;
        case 5:
            strncat(roman, "V", 1);
            break;
        case 6:
            strncat(roman, "VI", 2);
            break;
        case 7:
            strncat(roman, "VII", 3);
            break;
        case 8:
            strncat(roman, "VIII", 4);
            break;
        case 9:
            strncat(roman, "IX", 2);
            break;
        default:
            break;
    }
        
    return roman;   
}