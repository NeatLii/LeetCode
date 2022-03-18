class Solution {
  public:
    string intToRoman(int num) {
        const int value[] = {1000, 900, 500, 400, 100, 90, 50,
                             40,   10,  9,   5,   4,   1};
        const string symbol[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                 "XL", "X",  "IX", "V",  "IV", "I"};
        string ans;

        for (int i = 0; i < 13; i++) {
            int repeat = num / value[i];
            num -= repeat * value[i];
            while (repeat--) ans += symbol[i];
        }

        return ans;
    }
};