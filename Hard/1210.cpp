class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> Q;
        Q.push({0, 0, 0});
        map<vector<int>, bool> vis;
        map<vector<int>, int> dis;
        vis[{0, 0, 0}] = true, dis[{0, 0, 0}] = 0;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            int x = now[0], y = now[1], dir = now[2];
            if (dir == 0) {
                if (y + 2 < n && grid[x][y + 2] == 0) {
                    if (!vis.count({x, y + 1, 0})) {
                        vis[{x, y + 1, 0}] = true;
                        dis[{x, y + 1, 0}] = dis[now] + 1;
                        Q.push({x, y + 1, 0});
                    }
                }
                if (x + 1 < m && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    if (!vis.count({x + 1, y, 0})) {
                        vis[{x + 1, y, 0}] = true;
                        dis[{x + 1, y, 0}] = dis[now] + 1;
                        Q.push({x + 1, y, 0});
                    }
                }
                if (x + 1 < m && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    if (!vis.count({x, y, 1})) {
                        vis[{x, y, 1}] = true;
                        dis[{x, y, 1}] = dis[now] + 1;
                        Q.push({x, y, 1});
                    }
                }
            } else if (dir == 1) {
                if (x + 2 < m && grid[x + 2][y] == 0) {
                    if (!vis.count({x + 1, y, 1})) {
                        vis[{x + 1, y, 1}] = true;
                        dis[{x + 1, y, 1}] = dis[now] + 1;
                        Q.push({x + 1, y, 1});
                    }
                }
                if (y + 1 < n && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    if (!vis.count({x, y + 1, 1})) {
                        vis[{x, y + 1, 1}] = true;
                        dis[{x, y + 1, 1}] = dis[now] + 1;
                        Q.push({x, y + 1, 1});
                    } 
                }
                if (y + 1 < n && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    if (!vis.count({x, y, 0})) {
                        vis[{x, y, 0}] = true;
                        dis[{x, y, 0}] = dis[now] + 1;
                        Q.push({x, y, 0});
                    } 
                }
            }
        }
        if (!vis.count({m - 1, n - 2, 0})) return -1;
        return dis[{m - 1, n - 2, 0}];
    }
};