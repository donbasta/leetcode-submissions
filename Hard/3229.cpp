class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        using ll = long long;
        int n = nums.size();
        for (int i = 0; i < n; i++) nums[i] = target[i] - nums[i];
        ll ans = abs(nums[0]);
        for (int i = 1; i < n; i++) {
            if (1ll * nums[i] * nums[i - 1] > 0) { //same sign
                ans += max(0, abs(nums[i]) - abs(nums[i - 1]));
            } else {
                ans += abs(nums[i]);
            }
        }
        return ans;
    }
};