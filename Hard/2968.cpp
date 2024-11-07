class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = 1ll * nums[i] + (i ? pre[i - 1] : 0);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int piv = (i + mid) / 2;
                long long steps = 1ll * nums[piv] * (piv - i + 1) - (pre[piv] - (i ? pre[i - 1] : 0));
                steps += (pre[mid] - (piv ? pre[piv - 1] : 0)) - 1ll * nums[piv] * (mid - piv + 1);
                if (steps <= k) {
                    ret = max(ret, mid - i + 1);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return ret;
    }
};