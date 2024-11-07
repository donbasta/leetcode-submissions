class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length(); 
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = (s[0] == '*' ? 9 : (s[0] == '0' ? 0 : 1));
        for (int i = 2; i <= n; i++) {
            int tmp = 0;
            if (s[i - 1] == '*') {
                int cnt = (1ll * dp[i - 1] * 9) % MOD;
                tmp = (tmp + cnt) % MOD;
                if (s[i - 2] == '1') {
                    cnt = (1ll * dp[i - 2] * 9) % MOD;
                    tmp = (tmp + cnt) % MOD;
                } else if (s[i - 2] == '2') {
                    cnt = (1ll * dp[i - 2] * 6) % MOD;
                    tmp = (tmp + cnt) % MOD;
                } else if (s[i - 2] == '*') {
                    cnt = (1ll * dp[i - 2] * 15) % MOD;
                    tmp = (tmp + cnt) % MOD;
                }
            } else {
                int cur_dig = s[i - 1] - '0';
                if (cur_dig > 0) {
                    tmp = (tmp + dp[i - 1]) % MOD;
                }
                if (s[i - 2] == '*') {
                    if (cur_dig <= 6) {
                        int cnt = (1ll * dp[i - 2] * 2) % MOD;
                        tmp = (tmp + cnt) % MOD;
                    } else {
                        tmp = (tmp + dp[i - 2]) % MOD;
                    }
                } else {
                    int bruh = stoi(s.substr(i - 2, 2));
                    if (bruh >= 10 && bruh <= 26) {
                        tmp = (tmp + dp[i - 2]) % MOD;
                    }
                }
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};