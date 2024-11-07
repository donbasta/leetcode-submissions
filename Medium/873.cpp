class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[arr[i]] = i;
        dp[1][0] = 2;
        int ans = 2;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = 2;
                int a = arr[i] - arr[j];
                if (pos.find(a) == pos.end()) continue;
                dp[i][j] = max(dp[i][j], 1 + dp[j][pos[a]]);
                ans = max(ans, dp[i][j]);
            }
        }
        if (ans <= 2) return 0;
        return ans;
    }
};