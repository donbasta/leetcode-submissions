class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suf(n);
        for (int i = 0; i < n; i++) {
            pref[i] = (i ? (pref[i - 1] * nums[i]) : nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = ((i < n - 1) ? (suf[i + 1] * nums[i]) : nums[i]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) ans[i] = suf[1];
            else if (i == n - 1) ans[i] = pref[n - 2];
            else ans[i] = pref[i - 1] * suf[i + 1];
        }
        return ans;
    }
};