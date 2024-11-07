class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        // ans(i) = ar(0) + ... + ar(i) + pref(0) + ... + pref(i)
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }
        vector<long long> ans(n);
        long long cur = nums[0] + pref[0];
        ans[0] = cur;
        for (int i = 1; i < n; i++) {
            cur += (1ll * nums[i] + pref[i]);
            ans[i] = cur;
        }
        return ans;
    }
};