class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        // dp[i][j] = dp[i1][j - 1] for i1 < i such that nums[i1] != nums[i]
        // or dp[i][j] = dp[i1][j] + 1 for i1 < i such that nums[i1] == nums[i]

        int n = nums.size();
        unordered_map<int, vector<int>> dp;

        vector<pair<int, int>> b1(k + 5), b2(k + 5);
        b1[1] = make_pair(1, nums[0]);
        dp[nums[0]].resize(k + 5);
        dp[nums[0]][1] = 1;

        for (int i = 1; i < n; i++) {
            vector<int> cur(k + 5);
            if (!dp.count(nums[i])) dp[nums[i]].resize(k + 5);
            for (int j = 1; j <= k + 1; j++) {
                cur[j] = max(cur[j], dp[nums[i]][j] + 1);
                if (b1[j - 1].second != nums[i]) {
                    cur[j] = max(cur[j], b1[j - 1].first + 1);
                }
                if (b2[j - 1].second != nums[i]) {
                    cur[j] = max(cur[j], b2[j - 1].first + 1);
                }
            }
            for (int j = 1; j <= k + 1; j++) {
                dp[nums[i]][j] = max(dp[nums[i]][j], cur[j]);
                if (cur[j] > b1[j].first) {
                    b2[j] = b1[j];
                    b1[j] = make_pair(cur[j], nums[i]);
                } else if (cur[j] > b2[j].first) {
                    b2[j] = make_pair(cur[j], nums[i]);
                }
            }
        }

        int ans = 0;
        for (int j = k + 1; j >= 1; j--) {
            ans = max(ans, b1[j].first);
            ans = max(ans, b2[j].first);
        }

        return ans;
    }
};