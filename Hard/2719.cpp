class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        const int MOD = 1e9 + 7;
        const int MX = 9 * 22;
        int dp[23][MX + 1];
        memset(dp, 0, sizeof(dp));

        if (max_sum > MX) max_sum = MX;
        if (min_sum > max_sum) return 0;

        for (int i = 0; i <= MX; i++) dp[0][i] = 1;
        for (int i = 0; i < 10; i++) dp[1][i] = i + 1;
        for (int i = 10; i <= MX; i++) dp[1][i] = 10;
        for (int i = 2; i <= 22; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k <= MX; k++) {
                    if (k >= j) {
                        dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
                    }
                }
            }
        }

        auto f = [&](string s, int mx_sum) -> int {
            int len = s.length();
            int ret = dp[len - 1][mx_sum];
            int cur_sum = 0;
            for (int i = 0; i < len; i++) {
                int cur_dig = s[i] - '0';
                int st = ((i == 0) ? 1 : 0);
                for (int j = st; j <= cur_dig - 1; j++) {
                    int need_sum = mx_sum - cur_sum - j;
                    if (need_sum < 0) break;
                    ret = (ret + dp[len - 1 - i][need_sum]) % MOD;
                }
                cur_sum += cur_dig;
                if (cur_sum > mx_sum) break;
            }
            if (cur_sum <= mx_sum) ret = (ret + 1) % MOD;
            return ret;
        };

        auto sum_digit = [&](string s) -> int {
            int ret = 0;
            for (auto c : s) {
                ret += (c - '0');
            }
            return ret;
        };

        int ans = f(num2, max_sum);
        ans = (ans - f(num1, max_sum)) % MOD;
        ans = (ans - f(num2, min_sum - 1)) % MOD;
        ans = (ans + f(num1, min_sum - 1)) % MOD;
        int cek = sum_digit(num1);
        if (cek <= max_sum && cek >= min_sum) ans = (ans + 1) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};