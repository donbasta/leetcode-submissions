class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r = nums.size(), c = nums[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            sort(nums[i].begin(), nums[i].end(), greater<>());
        }
        for (int i = 0; i < c; i++) {
            int tmp = 0;
            for (int j = 0; j < r; j++) {
                tmp = max(tmp, nums[j][i]);
            }
            ans += tmp;
        }
        return ans;
    }
};