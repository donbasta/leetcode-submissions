class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        multiset<int> ki, ka;
        int n = nums.size() / 3;
        vector<long long> pref(3 * n), suf(3 * n);
        long long sl = 0, sr = 0;
        for (int i = 0; i < n; i++) {
            ki.insert(nums[i]);
            sl += nums[i];
        }
        pref[n - 1] = sl;
        for (int i = n; i < 3 * n; i++) {
            int mx = *ki.rbegin();
            if (nums[i] < mx) {
                ki.erase(ki.find(mx));
                ki.insert(nums[i]);
                sl += nums[i] - mx;
            }
            pref[i] = sl;
        }
        for (int i = 3 * n - 1; i >= 2 * n; i--) {
            ka.insert(nums[i]);
            sr += nums[i];
        }
        suf[2 * n] = sr;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int mn = *ka.begin();
            if (nums[i] > mn) {
                ka.erase(ka.find(mn));
                ka.insert(nums[i]);
                sr += nums[i] - mn;
            }
            suf[i] = sr;
        }
        long long ans = 1e18;
        for (int i = n - 1; i <= 2 * n - 1; i++) {
            ans = min(ans, pref[i] - suf[i + 1]);
        }
        return ans;
    }
};