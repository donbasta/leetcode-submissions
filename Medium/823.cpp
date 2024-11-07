class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> idx;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<pair<int, int>>> lol(n);
        for (int i = 0; i < n; i++) idx[arr[i]] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long prod = 1ll * arr[i] * arr[j];
                if (prod > (long long) 1e9) break;
                if (idx.find(prod) == idx.end()) continue;
                lol[idx[prod]].emplace_back(i, j);
            }
        }
        int ans = 0;
        const int MOD = 1e9 + 7;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (auto x : lol[i]) {
                int add = (1ll * dp[x.first] * dp[x.second]) % MOD;
                if (x.first != x.second) add = (1ll * add * 2) % MOD;
                dp[i] = (dp[i] + add) % MOD;
            }
        }
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        if (ans < 0) ans += MOD;
        return ans; 
    }
};