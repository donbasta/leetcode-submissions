class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int pref[n];
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = nums[i] + pref[i - 1];
        vector<int> nw;
        auto get_sum = [&](int l, int r) -> int {
            return pref[r] - (l ? pref[l - 1] : 0);
        };
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                nw.push_back(get_sum(i, j));
            }
        }
        sort(nw.begin(), nw.end());
        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + nw[i]) % MOD;
        }
        return ans;
    }
};