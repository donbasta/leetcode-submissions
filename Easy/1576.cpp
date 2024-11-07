class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        auto next = [&](char c) -> char {
            int x = c - 'a';
            x = (x + 1) % 26;
            return (char)(x + 'a');
        };
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') continue;
            s[i] = 'a';
            while ((i > 0 && s[i] == s[i - 1]) || (i < n - 1 && s[i] == s[i + 1])) {
                s[i] = next(s[i]);
            }
        }
        return s;
    }
};