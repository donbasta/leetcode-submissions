class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> dp[n];

        for (int i = 0; i < numSlots; i++) {
            dp[0][1 << i][0] = ((i + 1) & nums[0]);
        }
        
        for (int i = 1; i < n; i++) {
            for (auto m1 : dp[i - 1]) {
                for (auto m2 : dp[i - 1][m1.first]) {
                    int s1 = m1.first, s2 = m2.first;
                    assert ((s1 & s2) == 0);
                    for (int j = 0; j < numSlots; j++) {
                        if ((s2 >> j) & 1) continue;
                        else if ((s1 >> j) & 1) {
                            dp[i][s1 ^ (1 << j)][s2 ^ (1 << j)] = max(dp[i][s1 ^ (1 << j)][s2 ^ (1 << j)], dp[i - 1][s1][s2] + (nums[i] & (j + 1)));
                        } else {
                            dp[i][s1 ^ (1 << j)][s2] = max(dp[i][s1 ^ (1 << j)][s2], dp[i - 1][s1][s2] + (nums[i] & (j + 1)));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (auto m1 : dp[n - 1]) {
            for (auto m2 : m1.second) {
                ans = max(ans, m2.second);
            }
        }
        return ans;
    }
};