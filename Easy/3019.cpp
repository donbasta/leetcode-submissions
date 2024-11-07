class Solution {
public:
    int countKeyChanges(string s) {
        const function<int(char)> conv = [&](char c) -> int {
            if (c <= 'Z' && c >= 'A') return c - 'A';
            return c - 'a';
        };
        int last = conv(s[0]);
        int n = s.length();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int now = conv(s[i]);
            if (now != last) ans++;
            last = now;
        }
        return ans;
    }
};