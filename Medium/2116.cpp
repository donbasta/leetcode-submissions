class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        int a = 0, sa = 0;
        int b = 0, sb = 0;
        if (n & 1) return false;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    a++, b++;
                } else {
                    a--, b--;
                }
            } else {
                a++, b--;
            }
            if (a < 0) {
                return false;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == ')') {
                    sa++, sb++;
                } else {
                    sa--, sb--;
                }
            } else {
                sa++, sb--;
            }
            if (sa < 0) {
                return false;
            }
        }

        return (a >= 0 && 0 >= b && sa >= 0 && 0 >= sb);
    }
};