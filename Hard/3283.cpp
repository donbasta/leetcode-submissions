class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        int sz = 50;
        int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

        int E[n + 1][n + 1];
        memset(E, -1, sizeof(E));
        map<pair<int, int>, int> id;
        id[make_pair(kx, ky)] = n;
        for (int i = 0; i < n; i++) {
            id[make_pair(positions[i][0], positions[i][1])] = i;
        }

        for (int i = 0; i <= n; i++) {
            queue<pair<pair<int, int>, int>> Q;
            bool vis[sz][sz];
            memset(vis, 0, sizeof(vis));
            
            if (i < n) {
                Q.emplace(make_pair(positions[i][0], positions[i][1]), 0);
                vis[positions[i][0]][positions[i][1]] = true;
            } else {
                Q.emplace(make_pair(kx, ky), 0);
                vis[kx][ky] = true;
            }
            
            E[i][i] = 0;

            while (!Q.empty()) {
                auto now = Q.front();
                int cx = now.first.first, cy = now.first.second, cur_dir = now.second;
                Q.pop();
                for (int k = 0; k < 8; k++) {
                    int nx = cx + dx[k], ny = cy + dy[k];
                    if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    if (id.count(make_pair(nx, ny))) {
                        int j = id[make_pair(nx, ny)];
                        E[i][j] = E[j][i] = cur_dir + 1;
                    }
                    Q.emplace(make_pair(nx, ny), cur_dir + 1);
                }
            }
        }
    
        int dp[1 << n][n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) dp[0][i] = 0;
        for (int mask = 1; mask < (1 << n) - 1; mask++) {
            int u = __builtin_popcount(mask);
            int val;
            for (int j = 0; j < n; j++) {
                if (u % 2 == n % 2) val = INT_MIN;
                else val = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (!((mask >> k) & 1)) continue;
                    if (u % 2 == n % 2) val = max(val, dp[mask ^ (1 << k)][k] + E[k][j]);
                    else val = min(val, dp[mask ^ (1 << k)][k] + E[k][j]);
                }
                dp[mask][j] = val;
            }
        }

        int fmask = (1 << n) - 1;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(ret, dp[fmask ^ (1 << i)][i] + E[n][i]);
        }
        return ret;
    }
};