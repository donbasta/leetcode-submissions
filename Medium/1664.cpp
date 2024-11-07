class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int pref[n];
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (i & 1) pref[i] = pref[i - 1] - nums[i];
            else pref[i] = pref[i - 1] + nums[i];
        }

        auto range = [&](int a, int b) -> int {
            if (a > b) return 0;
            return pref[b] - (a ? pref[a - 1] : 0);  
        };

        int ret = 0;
        for (int i = 0; i < n; i++) {
            int le = range(0, i - 1);
            int ri = range(i + 1, n - 1);
            ret += (ri == le);
        }
        return ret;
    }
};