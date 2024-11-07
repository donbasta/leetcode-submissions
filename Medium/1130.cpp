class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int mx[n][n];
        for (int i = 0; i < n; i++) {
            mx[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                mx[i][j] = max(mx[i][j - 1], arr[j]);
            }
        }
        int DP[n][n];
        memset(DP, -1, sizeof(DP));
        const function<int(int, int)> helper = [&](int l, int r) -> int {
            if (l == r) return 0;
            if (DP[l][r] != -1) return DP[l][r];
            int ret = INT_MAX;
            for (int i = l; i < r; i++) {
                int P = helper(l, i);
                int Q = helper(i + 1, r);
                ret = min(ret, P + Q + mx[l][i] * mx[i + 1][r]);
            }
            return DP[l][r] = ret;
        };
        return helper(0, n - 1);
    }
};