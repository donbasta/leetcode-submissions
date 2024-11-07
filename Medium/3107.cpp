using ll = long long;

class Solution {
public:
    ll minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll ans = 0;
        for (int i = n / 2 - 1; i >= 0; i--) {
            if (nums[i] > k) ans += nums[i] - k;
        }
        for (int i = n / 2 + 1; i < n; i++) {
            if (nums[i] < k) ans += k - nums[i];
        }
        ans += abs(nums[n / 2] - k);
        return ans;
    }
};