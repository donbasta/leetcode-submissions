class Solution {
public:
    string smallestGoodBase(string n) {
        using ll = long long;
        ll sn = stoll(n);
        ll N = 1e6;
        ll ans = sn - 1;
        for (int i = 2; i <= min(N, sn); i++) {
            ll cur = 1 + i;
            ll pw = i;
            while (cur < sn) {
                if (pw > sn / i) {
                    break;
                }
                pw *= i;
                if (cur > sn - pw) {
                    break;
                }
                cur += pw;
            }
            if (cur == sn) {
                return to_string(i);
            }
        }

        ll cek = sn * 4 - 3;
        ll sq_cek = ll(sqrtl(cek));
        if (sq_cek * sq_cek == cek) {
            ans = min(ans, (sq_cek - 1) / 2);
        }

        return to_string(ans);
    }
};