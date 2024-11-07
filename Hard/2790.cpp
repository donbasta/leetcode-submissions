class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        using ll = long long;

        sort(usageLimits.begin(), usageLimits.end());
        reverse(usageLimits.begin(), usageLimits.end());
        ll U = accumulate(usageLimits.begin(), usageLimits.end(), 0ll);

        ll tot = 1;
        ll cnt = 1;
        while (tot <= U) {
            cnt++;
            tot += cnt;
        }
        cnt--;
        cnt = min(cnt, (ll)usageLimits.size());
        // cout << cnt << '\n';

        auto ok = [&](ll cnt) -> bool {
            ll cur = 0;
            ll X = 1ll * (cnt) * (cnt + 1) / 2 - 1;
            for (int i = 1; i <= cnt; i++) {
                // f[i - 1] + f[i] + .... <= 2 + ... + (cnt - i + 1) 
                if (U - cur <= X) {
                    return false;
                }
                cur += usageLimits[i - 1];
                X -= (cnt - i + 1);

            }
            return true;
        };

        ll le = 1, ri = cnt, ans = 1;
        while (le <= ri) {
            ll mid = (le + ri) >> 1;
            if (ok(mid)) {
                ans = mid, le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }
        return ans;
    }
};