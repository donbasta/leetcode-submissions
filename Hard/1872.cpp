class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        long long pre[n], dp[n];
        pre[0] = stones[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + stones[i];
        dp[n - 1] = 0;
        long long mx = pre[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = mx;
            mx = max(mx, pre[i] - dp[i]);
        }
        return dp[0];
    }
};