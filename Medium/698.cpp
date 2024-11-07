class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot % k != 0) return false;
        int t1 = tot / k;

        int n = nums.size();
        int sum[1 << n];
        memset(sum, 0, sizeof(sum));
        vector<int> gr;
        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                sum[i] += nums[j];
            }
            if (sum[i] == t1) {
                gr.push_back(i);
            }
        }
        bool dp[1 << n];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i < (1 << n); i++) {
            if (sum[i] % t1 != 0) continue;
            for (auto c : gr) {
                if ((c | i) != i) continue;
                if (dp[i ^ c]) dp[i] = true;
            }
        }
        return dp[(1 << n) - 1];
    }
};