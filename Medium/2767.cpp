class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        if (s[0] == '0') return -1;
        int n = s.length();
        vector<int> dp(n, -1);
        int pw5 = 1;
        unordered_map<int, bool> ump;
        while (pw5 < 100000) {
            ump[pw5] = true;
            pw5 *= 5;
        }
        const function<int(int)> DP = [&](int idx) -> int {
            int tmp = INT_MAX;
            if (idx == n) return 0;
            if (dp[idx] != -1) return dp[idx];
            for (int i = idx; i < n; i++) {
                if (ump.find(stoi(s.substr(idx, i - idx + 1), nullptr, 2)) != ump.end() && (i == n - 1 || s[i + 1] == '1')) {
                    if (DP(i + 1) != -1) {
                        tmp = min(tmp, 1 + DP(i + 1));
                    }
                }
            }
            if (tmp == INT_MAX) {
                return -1;
            }
            return dp[idx] = tmp;
        };
        return DP(0);
    }
};