class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        vector<int> pos;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) pos.emplace_back(i);
        }
        int sz = pos.size();
        if (sz == 0) return n;
        int ans = 1;
        for (int i = 0; i < sz; i++) {
            int l = pos[i] - 1, r = pos[i];
            if (i > 0) {
                l = pos[i - 1];
            } else {
                l = 0;
            }
            if (i < sz - 1) {
                r = pos[i + 1] - 1;
            } else {
                r = n - 1;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};