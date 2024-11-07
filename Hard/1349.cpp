class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<vector<int>> dp(m + 1, vector<int>((1 << n) + 1, -1));
        vector<int> cant(m + 1);
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '#') tmp ^= (1 << j);
            }
            cant[i] = tmp;
        }
        for (int i = 0; i < (1 << n); i++) {
            if (i & (cant[0])) continue;
            bool cant = false;
            for (int k = 0; k < n - 1; k++) {
                if ((i & (1 << k)) && (i & (1 << (k + 1)))) {
                    cant = true;
                    break;
                }
            }
            if (cant) continue;
            dp[0][i] = __builtin_popcount(i);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (j & (cant[i])) continue;
                bool cant = false;
                for (int k = 0; k < n - 1; k++) {
                    if ((j & (1 << k)) && (j & (1 << (k + 1)))) {
                        cant = true;
                        break;
                    }
                }
                if (cant) continue;
                int add = __builtin_popcount(j);
                for (int k = 0; k < (1 << n); k++) {
                    if (dp[i - 1][k] == -1) continue;
                    bool cantt = false;
                    for (int l = 0; l < n; l++) {
                        if (!(j & (1 << l))) continue;
                        if ((l > 0) && (k & (1 << (l - 1)))) {cantt = true; break;}
                        if ((l < (n - 1)) && (k & (1 << (l + 1)))) {cantt = true; break;}
                    }
                    if (cantt) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + add);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            ans = max(ans, dp[m - 1][i]);
        }
        return ans;
    }
};