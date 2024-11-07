class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n), suf(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];
        suf[n - 1] = nums.back();
        for (int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] + nums[i];
        long long ans = 1e18;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            long long kiri = pref[i] / (i + 1);
            long long kanan = ((i < n - 1) ? (suf[i + 1] / (n - 1 - i)) : 0);
            long long sel = abs(kiri - kanan);
            if (sel < ans) {
                ans = sel;
                idx = i;
            }
        }
        return idx;
    }
};