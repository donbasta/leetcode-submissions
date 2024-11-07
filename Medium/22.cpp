class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n == 1) {
            ret.push_back("()");
            return ret;
        }

        const function<void(int, int, string&)> rec = [&](int a, int b, string& tmp) -> void {
            if ((a == 0) && (b == 0)) {
                ret.push_back(tmp);
                return;
            }
            if (a == b) {
                tmp.push_back('(');
                rec(a - 1, b, tmp);
                tmp.pop_back();
            } else if ((a > 0) && (b > 0)) {
                tmp.push_back('(');
                rec(a - 1, b, tmp);
                tmp.pop_back();
                tmp.push_back(')');
                rec(a, b - 1, tmp);
                tmp.pop_back();
            } else if (a == 0) {
                tmp.push_back(')');
                rec(a, b - 1, tmp);
                tmp.pop_back();
            }
        };

        string cur;
        rec(n, n, cur);

        return ret;
    }
};