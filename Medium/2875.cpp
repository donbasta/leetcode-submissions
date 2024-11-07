class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> pref(n * 2);
        for (int i = 0; i < n; i++) {
            pref[i] = (i ? pref[i - 1] : 0ll) + nums[i];
        }
        for (int i = n; i < 2 * n; i++) {
            pref[i] = pref[i - 1] + nums[i - n];
        }
        int ans = INT_MAX;
        long long T = (long long) target;
        if (T % pref[n - 1] == 0) {
            return (T / pref[n - 1]) * n;
        }
        int len = (T / pref[n - 1]) * n;
        {
            long long sisa = T % pref[n - 1];
            int ujung = INT_MAX;
            unordered_map<long long, int> pos;
            pos[0ll] = 0;
            for (int i = 0; i < n * 2; i++) {
                if (pos.count(pref[i] - sisa)) {
                    ujung = min(ujung, i + 1 - pos[pref[i] - sisa]);
                }
                pos[pref[i]] = i + 1;
            }
            if (ujung != INT_MAX) {
                ans = min(ans, len + ujung);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;

    }
};