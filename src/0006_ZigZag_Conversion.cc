class Solution {
  public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        string ans;
        int t = 2 * numRows - 2;  //周期 = n + (n-2) = 2n-2
        for (int row = 0; row < numRows; ++row) {
            for (int i = 0; i + row < s.size(); i += t) {
                //每一行的第一个字符
                ans += s[i + row];
                //初首尾行外，每一行的第二个字符
                if (row != 0 && row != numRows - 1
                    && i + (t - row) < s.size()) {
                    ans += s[i + (t - row)];
                }
            }
        }

        return ans;
    }
};
