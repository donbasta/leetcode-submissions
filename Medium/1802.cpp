class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if (maxSum == n) return 1;
        long long lo = 2, hi = 1e9;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            long long sum = mid;
            if (index > 0) {
                if (mid > index) {
                    sum += 1ll * mid * index - (1ll * index * (index + 1)) / 2;
                } else {
                    sum += 1ll * mid * (mid - 1) / 2;
                    sum += (index - mid + 1);
                }
            }
            if (index < n - 1) {
                int lmao = (n - 1 - index);
                if (mid > lmao) {
                    sum += 1ll * mid * lmao - (1ll * lmao * (lmao + 1)) / 2;
                } else {
                    sum += 1ll * mid * (mid - 1) / 2;
                    sum += (lmao - mid + 1);
                }
            }
            // cout << mid << ' ' << sum << '\n';
            if (sum <= (long long)maxSum) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};