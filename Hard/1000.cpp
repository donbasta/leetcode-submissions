class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if (n == 1) return 0;
        int prf[n];
        memset(prf, 0, sizeof(prf));
        for (int i = 0; i < n; i++) {
            prf[i] = (i ? prf[i - 1] : 0) + stones[i];
        }
        auto get = [&](int l, int r) -> int {
            return prf[r] - (l ? prf[l - 1] : 0);
        };

        if (k == 2) {
            int dp[n][n];
            for (int i = 0; i < n; i++) dp[i][i] = 0;
            for (int i = 0; i < n - 1; i++) dp[i][i + 1] = stones[i] + stones[i + 1];
            for (int len = 3; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int tmp = INT_MAX;
                    for (int x = i; x < i + len - 1; x++) {
                        tmp = min(tmp, dp[i][x] + dp[x + 1][i + len - 1] + get(i, i + len - 1));
                    }
                    dp[i][i + len - 1] = tmp;
                }
            }
            return dp[0][n - 1];
        }
        if (k == 3) {
            if (n % (k - 1) != 1) return -1;
            int dp[n][n];
            for (int i = 0; i < n; i++) dp[i][i] = 0;
            for (int i = 0; i < n - 2; i++) dp[i][i + 2] = get(i, i + 2);
            for (int len = 5; len <= n; len += 2) {
                for (int i = 0; i <= n - len; i++) {
                    int tmp = INT_MAX;
                    for (int x = i + 1; x < i + len; x += 2) {
                        for (int y = x + 1; y < i + len; y += 2) {
                            if (dp[i][x - 1] != -1 && dp[x][y - 1] != -1 && dp[y][i + len - 1] != -1) {
                                tmp = min(tmp, dp[i][x - 1] + dp[x][y - 1] + dp[y][i + len - 1] + get(i, i + len - 1));
                            }
                        }
                    }
                    dp[i][i + len - 1] = tmp;
                }
            }
            return dp[0][n - 1];
        }
        if (n % (k - 1) != 1) return -1;

        map<vector<int>, int> mp;
        function<int(const vector<int>&)> go = [&](const vector<int>& state) -> int {
            if (mp.count(state)) return mp[state];
            if (state.size() == k) return mp[state] = prf[n - 1];
            int ret = INT_MAX;
            int sz = state.size();
            vector<int> prv(sz - k + 1);
            for (int i = 1; i <= sz - k; i++) prv[i] = state[i + k - 1];
            for (int i = 0; i < k; i++) prv[0] += state[i];
            prv[0]++;
            int cur = prv[0], lmao = 0;
            ret = min(ret, go(prv) + get(0, cur * (k - 1)));
            for (int i = 1; i <= sz - k; i++) {
                lmao += state[i - 1];
                cur -= state[i - 1];
                cur += state[i + k - 1];
                prv[i - 1] = state[i - 1];
                prv[i] = cur;
                ret = min(ret, go(prv) + get(lmao * (k - 1) + i, cur * (k - 1) + lmao * (k - 1) + i));
            }
            return mp[state] = ret;
        };

        return go(vector<int>(n, 0));
    }
};