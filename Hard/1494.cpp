class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        int need[n], must[n];
        memset(need, 0, sizeof(need));
        memset(must, 0, sizeof(must));
        for (auto r : relations) {
            need[r[1] - 1] ^= (1 << (r[0] - 1));
            must[r[0] - 1] ^= (1 << (r[1] - 1));
        }

        const int INF = 1e9;
        int dp[1 << n];
        for (int i = 0; i < (1 << n); i++) dp[i] = INF;
        dp[0] = 0;
        for (int i = 1; i < (1 << n); i++) {
            int mask = i;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (!((mask >> j) & 1)) continue;
                if ((need[j] | mask) != mask) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (!((mask >> j) & 1)) continue;
                if ((must[j] & mask) > 0) {
                    tmp ^= (1 << j);
                }
            }
            int rem = (mask ^ tmp);
            int nw = __builtin_popcount(rem);
            if (nw <= k) {
                dp[i] = min(dp[i], dp[tmp] + 1);
            } else {
                for (int j = rem; j > 0; j = (j - 1) & rem) {
                    if (__builtin_popcount(j) < nw - k) continue;
                    dp[i] = min(dp[i], dp[tmp ^ j] + 1);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};