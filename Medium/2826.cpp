class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pre(4, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 3; j++) {
                pre[j][i + 1] = pre[j][i] + (nums[i] == j);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int cnt1 = i - pre[1][i];
            for (int j = i; j <= n; j++) {
                int cnt2 = j - i - (pre[2][j] - pre[2][i]);
                int cnt3 = n - j - (pre[3][n] - pre[3][j]);
                ans = min(ans, cnt1 + cnt2 + cnt3);
            }
        }
        return ans;
    }
};