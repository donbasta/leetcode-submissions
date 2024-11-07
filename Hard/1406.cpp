class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = stoneValue[i] + (i ? pre[i - 1] : 0);
        }
        int tot = pre[n - 1];
        vector<vector<int>> memo(n + 1, vector<int>(2, -1));
        const int INF = 2e9;
        const function<int(int, int)> score = [&](int pos, int player) -> int {
            if (pos >= n) return 0;
            if (memo[pos][player] != -1) return memo[pos][player];
            if (player == 1) {
                return memo[pos][player] = tot - (pos ? pre[pos - 1] : 0) - score(pos, 0);
            }
            int tmp = stoneValue[pos];
            int ret = -INF;
            for (int i = pos + 1; i <= min(n, pos + 3); i++) {
                ret = max(ret, tmp + score(i, 1 - player));
                if (i < n) tmp += stoneValue[i];
            }
            return memo[pos][player] = ret;
        };
        int alice = score(0, 0);
        int bob = tot - alice;
        return (alice > bob ? "Alice" : (alice < bob ? "Bob" : "Tie"));
    }
};