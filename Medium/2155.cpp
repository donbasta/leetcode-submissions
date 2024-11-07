class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 2), suf(n + 2);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i + 1] = suf[i + 2] + (nums[i] == 1);
        }
        int mx = -1;
        for (int i = 0; i <= n; i++) {
            mx = max(mx, pref[i] + suf[i + 1]);
        }
        vector<int> ret;
        for (int i = 0; i <= n; i++) {
            if (pref[i] + suf[i + 1] == mx) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};