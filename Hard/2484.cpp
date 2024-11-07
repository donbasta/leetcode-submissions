class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        vector<vector<vector<int>>> le(n + 2, vector<vector<int>>(10, vector<int>(10)));
        vector<vector<vector<int>>> ri(n + 2, vector<vector<int>>(10, vector<int>(10)));
        vector<vector<int>> cnt_l(n + 2, vector<int>(10));
        vector<vector<int>> cnt_r(n + 2, vector<int>(10));
        for (int i = 0; i < n; i++) {
            int cur_dig = s[i] - '0';
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    le[i + 1][j][k] = le[i][j][k];
                }
            }
            for (int j = 0; j < 10; j++) {
                le[i + 1][j][cur_dig] = (le[i + 1][j][cur_dig] + cnt_l[i][j]) % MOD;
            }
            for (int j = 0; j < 10; j++) cnt_l[i + 1][j] = cnt_l[i][j];
            cnt_l[i + 1][cur_dig]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            int cur_dig = s[i] - '0';
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    ri[i + 1][j][k] = ri[i + 2][j][k];
                }
            }
            for (int j = 0; j < 10; j++) {
                ri[i + 1][j][cur_dig] = (ri[i + 1][j][cur_dig] + cnt_r[i + 2][j]) % MOD;
            }
            for (int j = 0; j < 10; j++) cnt_r[i + 1][j] = cnt_r[i + 2][j];
            cnt_r[i + 1][cur_dig]++;
        }
        int ans = 0;
        for (int i = 3; i <= n - 2; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    int tmp = (1ll * le[i - 1][j][k] * ri[i + 1][j][k]) % MOD;
                    ans = (ans + tmp) % MOD;
                }
            }
        }
        return ans;
    }
};