class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        using ll = long long;
        vector<ll> ret;
        if (finalSum & 1) {
            return ret;
        }
        // 2 + 4 + ... + 2k <= finalSum
        // k * (k + 1) <= finalSum
        ll l = 1, r = 2e5, piv = -1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (mid * (mid + 1) > finalSum) {
                r = mid - 1;
            } else {
                piv = mid;
                l = mid + 1;
            }
        }
        assert (piv != -1);
        ll tot = 0;
        for (int i = 1; i < piv; i++) {
            tot += 2ll * i;
            ret.push_back(2ll * i);
        }
        ret.push_back(finalSum - tot);
        return ret;
    }
};