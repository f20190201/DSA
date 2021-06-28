// We map a digit in a position to a unique string
// 1 <= A <= 3999

string Solution::intToRoman(int A) {
    vector<string> ones = {"" , "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> tens = {"" , "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> hundreds = {"" , "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> thousands = {"" , "M", "MM", "MMM"};

    return (thousands[(A/1000) % 10] + hundreds[(A/100)%10] + tens[(A/10)%10] + ones[A%10]);



}
