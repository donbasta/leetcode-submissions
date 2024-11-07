class Solution {
public:
    const int MOD = 1e9 + 7;
    inline void ckadd(int& x, int y) {
        x += y;
        if (x >= MOD) x -= MOD;
    }
    inline int sub(int x, int y) {
        int ret = x - y;
        if (ret < 0) ret += MOD;
        return ret; 
    }

    int distinctSequences(int n) {
        if (n == 1) return 6;
        if (n == 2) return 22;

       int d2[n + 1][7][7];
       int d1[n + 1][7];
       memset(d1, 0, sizeof(d1));
       memset(d2, 0, sizeof(d2));
       const int MOD = 1e9 + 7;

       for (int i = 1; i <= 6; i++) d1[1][i] = 1;

        vector<int> adj[7];
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                if (i == j) continue;
                if (__gcd(i, j) > 1) continue;
                adj[i].push_back(j);
            }
        }

       for (int i = 2; i <= n; i++) {
           for (int j = 1; j <= 6; j++) {
                for (auto k : adj[j]) {
                   if (j == k) continue;
                   if (__gcd(j, k) > 1) continue;
                   d2[i][j][k] = sub(d1[i - 1][k], d2[i - 1][k][j]);
                   ckadd(d1[i][j], d2[i][j][k]);
                }
           }
       }
       int ans = 0;
       for (int i = 1; i <= 6; i++) {
        //    cout << i << ' ' << dp[n][i] << '\n';
           ckadd(ans, d1[n][i]);
       }
       if (ans < 0) ans += MOD;
       return ans;
   }
};
