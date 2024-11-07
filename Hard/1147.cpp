class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.length();
        int md = (n + 1) / 2;
        const function<vector<int>(const string&)> common_prefsuf_lengths = [&](const string& s) -> vector<int> {
            int n = s.length();
            vector<int> pi(n);
            for (int i = 1; i < n; i++) {
                int j = pi[i - 1];
                while (j > 0 && s[j] != s[i]) {
                    j = pi[j - 1];
                }
                if (s[j] == s[i]) j++;
                pi[i] = j;
            }
            vector<int> prefsuflen;
            int j = pi[n - 1];
            while (j > 0) {
                prefsuflen.push_back(j);
                j = pi[j - 1];
            }
            return prefsuflen;
        };
        vector<vector<int>> pref(n);
        for (int i = 0; i < md; i++) {
            pref[i] = common_prefsuf_lengths(text.substr(i, n - 2 * i));
        }
        vector<int> DP(n, -1);
        const function<int(int)> dp = [&](int idx) -> int {
            if (idx >= md) return 0;
            if (DP[idx] != -1) return DP[idx];
            int tmp = 1;
            for (auto len : pref[idx]) {
                tmp = max(tmp, 2 + dp(idx + len));
            }
            return DP[idx] = tmp;
        };
        return dp(0);
    }
};