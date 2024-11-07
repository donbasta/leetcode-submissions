class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<vector<int>> prefLessThan(n + 1, vector<int>(n + 5)), suffMoreThan(n + 1, vector<int>(n + 5));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                prefLessThan[i][j] = (i ? prefLessThan[i - 1][j] : 0) + (nums[i] <= j);
            }
        }

        for (int i = 1; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] > nums[j]) {
                    int less = prefLessThan[i - 1][nums[j] - 1];
                    int more = (n - nums[i]) - (j - prefLessThan[j - 1][nums[i]]);
                    // int more = suffMoreThan[j + 1][nums[i] + 1];
                    ans += 1ll * less * more;
                }
            }
        }
        return ans;
    }
};