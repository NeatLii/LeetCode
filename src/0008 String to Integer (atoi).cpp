class Solution {
  public:
    int myAtoi(string s) {
        //有限状态自动机DFA
        //              ' '     +/-     number      other
        // start        start   signed  in_number   end
        // signed       end     end     in_number   end
        // in_number    end     end     in_number   end
        // end          end     end     end         end
        int map[4][4] = {
            {0, 1, 2, 3}, {3, 3, 2, 3}, {3, 3, 2, 3}, {3, 3, 3, 3}};
        int status = 0;
        bool sign = true;
        long long sum = 0;

        for (char c : s) {
            status = map[status][getKind(c)];
            if (status == 0) continue;
            if (status == 3) break;
            if (status == 1)
                sign = c == '+';
            else if (status == 2) {
                sum = sum * 10 + (c - '0');
                if (sign && sum > INT_MAX) return INT_MAX;
                if (!sign && -sum < INT_MIN) return INT_MIN;
            }
        }

        if (sign)
            return sum;
        else
            return -sum;
    }

    inline int getKind(char c) {
        if (isspace(c)) return 0;
        if (c == '-' || c == '+') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
};