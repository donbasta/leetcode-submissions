class Solution {
public:
    int scoreOfParentheses(string s) {
        const function<bool(int, int)> balanced = [&](int l, int r) -> int {
            int cur = 0;
            for (int i = l; i <= r; i++) {
                if (s[i] == '(') cur++;
                else cur--;
                if (cur < 0) return false;
            }
            return cur == 0;
        };
        const function<int(int, int)> get_score = [&](int l, int r) -> int {
            if (r == l + 1) return 1;
            if (balanced(l + 1, r - 1)) return 2 * get_score(l + 1, r - 1);
            int cur = 0, ret = 0;
            int st = l;
            for (int i = l; i <= r; i++) {
                if (s[i] == '(') cur++;
                else cur--;
                if (cur == 0) {
                    ret += get_score(st, i);
                    st = i + 1;
                }
            }
            return ret;
        };
        int n = s.length();
        return get_score(0, n - 1);
    }
};