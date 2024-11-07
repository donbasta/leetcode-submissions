class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& req) {
        sort(req.begin(), req.end());
        int sz = req.size();
        for (int i = 1; i < sz; i++) {
            if (req[i][1] < req[i - 1][1]) {
                return 0;
            }
        }
        using ll = long long;
        const ll MOD = 1e9 + 7;
        vector<vector<ll>> dp(n + 5, vector<ll>(405));
        
        dp[1][0] = 1;
        
        int ptr = 0;
        if (ptr < sz && req[ptr][0] == 0) {
            for (int inv = 0; inv <= 400; inv++) {
                if (inv != req[ptr][1]) dp[1][inv] = 0;
            }
            ptr++;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int inv = 0; inv <= 400; inv++) {
                for (int j = inv; j >= max(0, inv - (i - 1)); j--) {
                    dp[i][inv] = (dp[i][inv] + dp[i - 1][j]) % MOD;
                }
            }
            if (ptr < sz && req[ptr][0] == i - 1) {
                for (int inv = 0; inv <= 400; inv++) {
                    if (inv != req[ptr][1]) dp[i][inv] = 0;
                }
                ptr++;
            }
        }
        
        // for (int i = 1; i <= 3; i++) {
        //     for (int j = 0; j <= 3; j++) {
        //         cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        //     }
        // }
        
        
        return dp[n][req.back()[1]];
    }
};