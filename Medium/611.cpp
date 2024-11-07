class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = nums[i] + nums[j];
                int id = lower_bound(nums.begin() + j + 1, nums.end(), x) - nums.begin();
                ans += (id - 1 - j);
            }
        }
        return ans;
    }
};