class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(4));
        vector<vector<int>> mx(n + 1, vector<int>(4));
        vector<vector<int>> start_last(n + 1, vector<int>(4, -1));
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
        for (int i = 1; i <= 3; i++) {
            for (int j = k; j <= n; j++) {
                dp[j][i] = (pre[j] - pre[j - k]) + mx[j - k][i - 1];
                if (mx[j - 1][i] < dp[j][i]) {
                    start_last[j][i] = j - k + 1;
                } else {
                    start_last[j][i] = start_last[j - 1][i];
                }
                mx[j][i] = max(mx[j - 1][i], dp[j][i]); 
            }
        }
        int a, b, c;
        a = start_last[n][3];
        b = start_last[a - 1][2];
        c = start_last[b - 1][1];
        return {c - 1, b - 1, a - 1};
    }
};