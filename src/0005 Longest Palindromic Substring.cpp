class Solution {
  public:
    int expand(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;  //返回臂长
    }

    string longestPalindrome(string s) {
        string s_expand = "#";
        for (char c : s) {
            s_expand += c;
            s_expand += '#';
        }

        vector<int> arm_len;
        int start = 0, end = -1;
        int most_right = -1, j = -1;
        for (int i = 0; i < s_expand.size(); i++) {
            int cur_arm_len;
            if (most_right >= i) {
                int min_arm_len = min(arm_len[j * 2 - i], most_right - i);
                cur_arm_len =
                    expand(s_expand, i - min_arm_len, i + min_arm_len);
            }
            else
                cur_arm_len = expand(s_expand, i, i);
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > most_right) {
                most_right = i + cur_arm_len;
                j = i;
            }
            if (cur_arm_len * 2 + 1 > end - start + 1) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i) {
            if (s_expand[i] != '#') ans += s_expand[i];
        }
        return ans;
    }
};