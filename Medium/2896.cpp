class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> beda;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) beda.push_back(i);
        }
        if (beda.empty()) return 0;
        int sz = beda.size();
        if (sz & 1) {
            return -1;
        }
        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int i = 0; i < sz - 1; i++) dp[i][i + 1] = min(x, beda[i + 1] - beda[i]);
        for (int len = 4; len <= sz; len++) {
            for (int i = 0; i + len - 1 < sz; i++) { //dp[i][i + len - 1]
                int tmp = INT_MAX;
                for (int j = i + len - 2; j >= i; j -= 2) {
                    tmp = min(tmp, min(x, beda[i + len - 1] - beda[j]) + (j ? dp[i][j - 1] : 0) + dp[j + 1][i + len - 2]);
                }
                dp[i][i + len - 1] = tmp;
            }
        }
        return dp[0][sz - 1];
    }
};