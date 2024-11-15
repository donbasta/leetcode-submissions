class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        auto ok = [&](int x, int y) -> bool {
            vector<bool> a1(26), a2(26);
            for (int i = x; i <= y; i++) {
                if (s[i] >= 'a' && s[i] <= 'z') a1[s[i] - 'a'] = true;
                else a2[s[i] - 'A'] = true;
            }
            for (int i = 0; i < 26; i++) {
                if (a1[i] && !a2[i]) return false;
                if (a2[i] && !a1[i]) return false;
            }
            return true;
        };
        for (int len = n; len >= 2; len--) {
            for (int i = 0; i + len - 1 <= n - 1; i++) {
                if (ok(i, i + len - 1)) return s.substr(i, len);
            }
        }
        return "";
    }
};