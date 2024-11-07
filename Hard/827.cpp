class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cur_id = 0;
        vector<int> area;
        vector<vector<int>> id(m, vector<int>(n, -1));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        //do initial island flood fill here;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (id[i][j] != -1) continue;
                queue<pair<int, int>> Q;
                id[i][j] = cur_id;
                int cur_area = 1;
                Q.emplace(i, j);
                while (!Q.empty()) {
                    pair<int, int> now = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int ni = now.first + dx[k], nj = now.second + dy[k];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        if (grid[ni][nj] == 0) continue;
                        if (id[ni][nj] != -1) continue;
                        id[ni][nj] = cur_id;
                        cur_area++;
                        Q.emplace(ni, nj);
                    }
                }
                area.push_back(cur_area);
                cur_id++;
            }
        }
        int ans = 0;
        if (!area.empty()) {
             ans = *max_element(area.begin(), area.end());
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                set<int> se;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (grid[ni][nj] == 0) continue;
                    se.insert(id[ni][nj]);
                }
                int nw = 1;
                for (auto e : se) nw += area[e];
                ans = max(ans, nw);
            }
        }
        return ans;
    }
};