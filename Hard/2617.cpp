struct Segtree {
    vector<int> tree;
    const int INF = 2e9;
    Segtree(int n) {
        tree.assign(4 * n + 5, INF);
    }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    int que(int v, int s, int e, int l, int r) {
        if (l > r) return INF;
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return que(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return que(v << 1 | 1, mid + 1, e, l, r);
        return min(que(v << 1, s, mid, l, mid), que(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<Segtree> row, col;
        for (int i = 0; i < m; i++) {
            row.push_back(Segtree(n));
        }
        for (int i = 0; i < n; i++) {
            col.push_back(Segtree(m));
        }
        const int INF = 2e9;
        vector<vector<int>> dp(m, vector<int>(n, INF));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0 && (i < m - 1 || j < n - 1)) continue;
                int nx = INF;
                if (i == m - 1 && j == n - 1) dp[i][j] = 1;
                else {
                    if (j < n - 1) {
                        nx = min(nx, (row[i].que(1, 0, n - 1, j + 1, min(n - 1, j + grid[i][j]))));
                    }
                    if (i < m - 1) {
                        nx = min(nx, (col[j].que(1, 0, m - 1, i + 1, min(m - 1, i + grid[i][j]))));
                    }
                    if (nx < INF) dp[i][j] = 1 + nx;
                }
                row[i].upd(1, 0, n - 1, j, dp[i][j]);
                col[j].upd(1, 0, m - 1, i, dp[i][j]);
            }
        }
        if (dp[0][0] == INF) return -1;
        return dp[0][0];
    }
};