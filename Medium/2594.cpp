class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        using ll = long long;
        ll L = 1, R = 1ll * cars * cars * 100;
        ll ans = -1;

        auto ok = [&](ll mn) -> bool {
            ll tot = 0;
            for (auto r : ranks) {
                tot += ll(sqrtl(mn / r));
            }
            return tot >= 1ll * cars;
        };

        while (L <= R) {
            ll M = (L + R) >> 1;
            if (ok(M)) {
                ans = M;
                R = M - 1;
            }  else {
                L = M + 1;
            }
        }
        return ans;
    }
};