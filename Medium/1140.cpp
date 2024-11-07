class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<unordered_map<int, int>> DP(n);
        vector<int> pre(n);
        pre[0] = piles[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + piles[i];
        const function<int(int, int)> dp = [&](int idx, int m) -> int {
            if (idx >= n) return 0;
            if (DP[idx].find(m) != DP[idx].end()) return DP[idx][m];
            int ret = 0;
            int rem = pre[n - 1] - (idx ? pre[idx - 1] : 0);
            for (int x = 1; x <= 2 * m; x++) {
                ret = max(ret, rem - dp(idx + x, max(m, x)));
            }
            return DP[idx][m] = ret;
        };
        return dp(0, 1);
    }
};