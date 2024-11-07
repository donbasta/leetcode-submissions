class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        for (auto x : nums1) tmp.push_back(x);
        sort(tmp.begin(), tmp.end());
        long long lmao = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) lmao += abs(nums1[i] - nums2[i]);
        long long ans = lmao;
        for (int i = 0; i < n; i++) {
            lmao -= abs(nums1[i] - nums2[i]);
            int idx = lower_bound(tmp.begin(), tmp.end(), nums2[i]) - tmp.begin();
            int lol = INT_MAX;
            if (idx < n) lol = min(lol, abs(tmp[idx] - nums2[i]));
            if (idx > 0) lol = min(lol, abs(tmp[idx - 1] - nums2[i]));
            ans = min(ans, lol + lmao);
            lmao += abs(nums1[i] - nums2[i]);
        }
        long long MOD = 1e9 + 7;
        ans %= MOD;
        return ans;
    }
};