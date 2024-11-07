class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        long long dp[23][20][11], ndp[23][20][11]; //selisih ganjil - genap, modulo, count digit
        int pw10[11];
        pw10[0] = 1;
        for (int i = 1; i <= 10; i++) {
            pw10[i] = (1ll * pw10[i - 1] * 10) % k;
        }

        const int B = 11;
        memset(dp, 0, sizeof(dp));
        memset(ndp, 0, sizeof(ndp));
        for (int i = 0; i <= 9; i++) {
            int sel = ((i & 1) ? 1 : -1);
            dp[sel + B][i % k][1]++;
            if (i >= 1) ndp[sel + B][i % k][1]++;
        }
        for (int d = 2; d <= 10; d++) {
            for (int sel = -d; sel <= d; sel++) {
                for (int res = 0; res < k; res++) {
                    for (int i = 0; i <= 9; i++) {
                        int tam = (1ll * i * pw10[d - 1]) % k;
                        int res_prv = (res + k - tam) % k;
                        int sel_prv = ((i & 1) ? (sel - 1) : (sel + 1));
                        dp[sel + B][res][d] += dp[sel_prv + B][res_prv][d - 1];
                    }
                    for (int i = 1; i <= 9; i++) {
                        int tam = (1ll * i * pw10[d - 1]) % k;
                        int res_prv = (res + k - tam) % k;
                        int sel_prv = ((i & 1) ? (sel - 1) : (sel + 1));
                        ndp[sel + B][res][d] += dp[sel_prv + B][res_prv][d - 1];
                    }
                }
            }
        }
        auto f = [&](string s) -> long long {
            if (s == "0") return 0;
            int len = s.length();
            int cur_sel = 0;
            int cur_sum = 0;

            long long ans = 0;
            // ans = dp[B][0][len - 1];
            for (int i = 1; i < len; i++) {
                ans += ndp[B][0][i];
            }
            // cout << s << ' ' << ans << '\n';
            for (int i = 0; i < len; i++) {
                int st = (i == 0 ? 1 : 0);
                int cur_dig = s[i] - '0';
                for (int j = st; j < cur_dig; j++) {
                    int tmp_sel = (j & 1) ? (cur_sel + 1) : (cur_sel - 1);
                    int tmp_sum = (1ll * cur_sum + 1ll * j * pw10[len - 1 - i]) % k;
                    if (i == len - 1) {
                        ans += ((tmp_sel == 0) && (tmp_sum == 0));
                    } else {
                        ans += dp[B - tmp_sel][(k - tmp_sum) % k][len - 1 - i];
                    }
                }
                cur_sum = (1ll * cur_sum + 1ll * cur_dig * pw10[len - 1 - i]) % k;
                cur_sel = (cur_dig & 1) ? (cur_sel + 1) : (cur_sel - 1);
            }
            // cout << s << ' ' << cur_sel << ' ' << cur_sum << '\n';
            if (cur_sel == 0 && cur_sum == 0) ans++;
            // cout << ans << '\n';
            return ans;
        };
        string shigh = to_string(high);
        string slow = to_string(low - 1);
        return f(shigh) - f(slow);
    }
};