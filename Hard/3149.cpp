class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) return vector<int>{0, 1};
        int dp[1 << n][n][n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                dp[(1 << i) ^ (1 << j)][i][j] = abs(i - nums[j]) + abs(j - nums[i]);
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) <= 2) continue;
            for (int i = 0; i < n; i++) {
                if (!((mask >> i) & 1)) continue;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (!((mask >> j) & 1)) continue;
                    int tmp = INT_MAX;
                    for (int k = 0; k < n; k++) {
                        if (i == k || j == k) continue;
                        if (!((mask >> k) & 1)) continue;
                        tmp = min(tmp, dp[mask ^(1 << i)][k][j] - abs(k - nums[j]) + abs(k - nums[i]) + abs(i - nums[j]));
                    }
                    dp[mask][i][j] = tmp;
                }
            }
        }
        vector<int> ans;
        ans.push_back(0);
        int cur_mask = (1 << n) - 1;
        int mn = INT_MAX;
        int last = -1;
        for (int i = 1; i < n; i++) {
            if (dp[cur_mask][0][i] < mn) {
                mn = dp[cur_mask][0][i];
                last = i;
            }
        }
        ans.push_back(last);
        while (ans.size() < n) {
            cur_mask ^= (1 << last);
            int tmp = INT_MAX;
            int nx = -1;
            for (int i = 1; i < n; i++) {
                if (!((cur_mask >> i) & 1)) continue;
                int check = dp[cur_mask][0][i] + abs(nums[last]) + abs(last - nums[i]) - abs(nums[i]);
                if (tmp > check) {
                    tmp = check;
                    nx = i;
                }
            }
            ans.push_back(nx);
            last = nx;
        }
        return ans;
    }
};