class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        const auto F = [&](int i, int j) -> int { return i * n + j; };
        pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> from(m * n);
        vector<int> to(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = F(i, j);
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k].first, nj = j + dir[k].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (matrix[ni][nj] <= matrix[i][j]) continue;
                    to[F(ni, nj)]++;
                    from[F(i, j)].push_back(F(ni, nj));
                }
            }
        }
        queue<int> Q;
        vector<int> dp(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (to[F(i, j)] == 0) Q.push(F(i, j));
                dp[F(i, j)] = 1;
            }
        }
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto adj : from[now]) {
                dp[adj] = max(dp[adj], dp[now] + 1);
                to[adj]--;
                if (to[adj] == 0) {
                    Q.push(adj);
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < m * n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};