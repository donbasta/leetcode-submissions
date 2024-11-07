class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        ll l = 0, r = 1e18, piv = -1;
        int n = workerTimes.size();

        auto binser = [&](ll z) -> ll {
            //return greatest x such that x * (x + 1) / 2 <= z
            ll lo = 0, hi = z;
            ll ret = -1;
            while (lo <= hi) {
                ll mid = (lo + hi) >> 1;
                if (mid <= 2ll * z / (mid + 1)) {
                    ret = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ret;
        };

        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll height = 0;
            for (int i = 0; i < n; i++) {
                ll cur = workerTimes[i];
                height += binser(mid / cur);
                // cur * x * (x + 1) / 2 <= mid
                // x * (x + 1) / 2 <= mid / cur;
            }
            if (height >= mountainHeight) {
                piv = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return piv;
    }
};