class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        // dp[i][j] = dp[i1][j - 1] for i1 < i such that nums[i1] != nums[i]
        // or dp[i][j] = dp[i1][j] + 1 for i1 < i such that nums[i1] == nums[i]

        int n = nums.size();
        unordered_map<int, int> pos;

        vector<vector<int>> dp(n, vector<int>(k + 5));
        dp[0][1] = 1;
        pos[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k + 1; j++) {
                if (pos.count(nums[i])) {
                    dp[i][j] = dp[pos[nums[i]]][j] + 1;
                }
                for (auto kk : pos) {
                    if (kk.first == nums[i]) continue;
                    dp[i][j] = max(dp[i][j], dp[kk.second][j - 1] + 1);
                }
            }
            pos[nums[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k + 1; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};