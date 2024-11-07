class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        const int M = 60;
        const int INF = 2e9;
        vector<vector<int>> batas(M + 1);
        for (int i = 0; i <= M; i++) {
            batas[i] = {INF, -1, INF, -1};
        }
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = targetGrid[i][j];
                batas[cur][0] = min(batas[cur][0], j);
                batas[cur][1] = max(batas[cur][1], j);
                batas[cur][2] = min(batas[cur][2], i);
                batas[cur][3] = max(batas[cur][3], i);
            }
        }

        vector<vector<int>> from(M + 1);
        for (int i = 1; i <= M; i++) {
            if (batas[i][0] == INF) continue;
            for (int j = 1; j < i; j++) {
                if (batas[j][0] == INF) continue;
                int isectLeft = max(batas[i][0], batas[j][0]);
                int isectRight = min(batas[i][1], batas[j][1]);
                int isectTop = max(batas[i][2], batas[j][2]);
                int isectBottom = min(batas[i][3], batas[j][3]);
                if (isectLeft > isectRight || isectBottom < isectTop) continue;
                int cntI = 0, cntJ = 0;
                for (int ii = isectTop; ii <= isectBottom; ii++) {
                    for (int jj = isectLeft; jj <= isectRight; jj++) {
                        if (targetGrid[ii][jj] == i) {
                            cntI++;
                        }
                        if (targetGrid[ii][jj] == j) {
                            cntJ++;
                        }
                    }
                }
                if (cntI > 0 && cntJ > 0) {
                    return false;
                }
                if (cntI > 0) {
                    from[j].emplace_back(i);
                } else if (cntJ > 0) {
                    from[i].emplace_back(j);
                }
            }
        }

        vector<int> color(M + 1);
        vector<int> parent(M + 1, -1);
        int cycle_start = -1, cycle_end = -1;

        const function<bool(int)> dfs = [&](int v) -> bool {
            color[v] = 1;
            for (int u : from[v]) {
                if (color[u] == 0) {
                    // parent[u] = v;
                    // return dfs(u);
                    if (dfs(u)) return true;
                }
                else if (color[u] == 1) {
                    cycle_end = v;
                    cycle_start = u;
                    return true;
                }
            }
            color[v] = 2;
            return false;
        };

        for (int i = 1; i <= M; i++) {
            if (color[i] == 0 && dfs(i)) break;
        }

        // cout << "TESTTTT\n";
        // cout << cycle_start << ' ' << cycle_end << '\n';

        // vector<int> cycle;
        // cycle.push_back(cycle_start);
        // for (int v = cycle_end; v != cycle_start; v = parent[v])
        //     cycle.push_back(v);
        // cycle.push_back(cycle_start);
        // reverse(cycle.begin(), cycle.end());

        // cout << "Cycle found: ";
        // for (int v : cycle)
        //     cout << v << " ";
        // cout << endl;

        return cycle_start == -1;

    }
};