class Solution {
public:
    string thousandSeparator(int n) {
        string ret;
        string s = to_string(n);
        int len = s.length();
        for (int i = len - 1; i >= 0; i--) {
            ret.push_back(s[i]);
            if ((len - 1 - i) % 3 == 2 && i != 0) ret.push_back('.');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};