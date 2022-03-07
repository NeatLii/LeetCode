class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        for(int &n : last) n = -1;
        uint i, start, len = 0;
        for(i = 0, start = 0; i < s.size(); i++){
            start = start>last[s[i]]+1 ? start : last[s[i]]+1;
            len = len>i-start+1 ? len : i-start+1;
            last[s[i]] = i;
        }
        return len;
    }
};
