class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            if (s[i] >= '1') {
                tmp += dp[i];
            }
            if (i > 0) {
                int lastTwo = stoi(s.substr(i - 1, 2));
                if (lastTwo >= 10 && lastTwo <= 26) {
                    tmp += dp[i - 1];
                }
            }
            dp[i + 1] = tmp;
        }
        return dp[n];
    }
};