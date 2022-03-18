class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        bool exist[128] = {};
        int left = 0, right = 0;
        int len = 0;
        while (left < s.size()) {
            while (!exist[s[right]]) {
                if (right == s.size() - 1) return max(len, right - left + 1);
                exist[s[right++]] = true;
            }
            len = max(len, right - left);
            while (exist[s[right]]) exist[s[left++]] = false;
        }
        return len;
    }
};