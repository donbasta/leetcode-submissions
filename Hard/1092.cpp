class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        vector<vector<pair<int, int>>> pre(n1 + 1, vector<pair<int, int>>(n2 + 1));
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = i; pre[i][0] = make_pair(i - 1, 0);
        }
        for (int i = 1; i <= n2; i++) {
            dp[0][i] = i; pre[0][i] = make_pair(0, i - 1);
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    pre[i][j] = make_pair(i, j - 1);
                    dp[i][j] = dp[i][j - 1] + 1;
                } else {
                    pre[i][j] = make_pair(i - 1, j);
                    dp[i][j] = dp[i - 1][j] + 1;
                }
                if (str1[i - 1] == str2[j - 1]) {
                    if (dp[i - 1][j - 1] + 1 < dp[i][j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        pre[i][j] = make_pair(i - 1, j - 1);
                    }
                }
            }
        }
        int c1 = n1, c2 = n2;
        string ret;
        while ((c1 > 0) || (c2 > 0)) {
            if (pre[c1][c2] == make_pair(c1 - 1, c2)) {
                ret.push_back(str1[c1 - 1]);
            } else if (pre[c1][c2] == make_pair(c1, c2 - 1)) {
                ret.push_back(str2[c2 - 1]);
            } else if (pre[c1][c2] == make_pair(c1 - 1, c2 - 1)) {
                assert (str1[c1 - 1] == str2[c2 - 1]);
                ret.push_back(str1[c1 - 1]);
            }
            int a = pre[c1][c2].first, b = pre[c1][c2].second;
            c1 = a, c2 = b;
            
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};