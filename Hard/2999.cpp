class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        using ll = long long;

        ll pw[18];
        pw[0] = 1;
        for (int i = 1; i < 18; i++) {
            pw[i] = pw[i - 1] * (limit + 1);
        }

        auto G = [&](ll x) -> bool {
            string sn = to_string(x);
            int len = sn.length();
            int ls = s.length();
            if (len < ls) return false;
            bool ok = true;
            for (int i = len - 1; i >= len - ls; i--) {
                ok &= (sn[i] == s[i - len + ls]);
            }
            if (!ok) return false;
            for (int i = 0; i < len - ls; i++) {
                ok &= (sn[i] - '0') <= limit;
            }
            return ok;
        };

        auto F = [&](ll x) -> ll {
            string sn = to_string(x);
            int len = sn.length();
            int ls = s.length();
            if (len < ls) return 0;
            ll ans = 0;

            bool ok = true;
            for (int i = 0; i < len - ls; i++) {
                int cur_dig = sn[i] - '0';
                int take = min(cur_dig - 1, limit) + 1;
                ans += 1ll * take * pw[len - ls - i - 1];
                if (cur_dig > limit) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (stoll(sn.substr(len - ls, ls)) >= stoll(s)) ans++;
            }

            return ans;
        };

        return F(finish) - F(start) + G(start);
    }
};