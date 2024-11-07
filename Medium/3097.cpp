class Solution {
   public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, r = n, ans = -1;

        const int B = 32;
        vector<vector<int>> pref(n, vector<int>(32));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < B; j++) {
                pref[i][j] = (i ? pref[i - 1][j] : 0) + ((nums[i] >> j) & 1);
            }
        }

        const function<bool(int)> ok = [&](int len) -> bool {
            int mx = 0;
            for (int i = len - 1; i < n; i++) {
                int tmp = 0;
                for (int j = 0; j < B; j++) {
                    int cnt = (pref[i][j] - (i >= len ? pref[i - len][j] : 0));
                    if (cnt > 0) tmp += 1 << j;
                }
                mx = max(mx, tmp);
            }
            return mx >= k;
        };

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};