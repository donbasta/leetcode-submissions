class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int add = max(0, nums[i - 1] + 1 - nums[i]);
            nums[i] += add;
            ans += add;
        }
        return ans;
    }
};