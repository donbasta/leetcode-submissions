class Solution {
public:
    vector<vector<vector<bool>>> vis, dp;

    bool util(int l1, int l2, int len, const string& s1, const string& s2) {
        if (vis[l1][l2][len]) return dp[l1][l2][len];
        if (len == 1) return s1[l1] == s2[l2];
        vis[l1][l2][len] = true;
        for (int i = 1; i < len; i++) {
            bool ok;
            ok = util(l1, l2, i, s1, s2) && util(l1 + i, l2 + i, len - i, s1, s2);
            if (ok) return dp[l1][l2][len] = true;
            ok = util(l1, l2 + len - i, i, s1, s2) && util(l1 + i, l2, len - i, s1, s2);
            if (ok) return dp[l1][l2][len] = true;
        }
        return dp[l1][l2][len] = false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vis.assign(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        dp.assign(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        return util(0, 0, n, s1, s2);
    }
};