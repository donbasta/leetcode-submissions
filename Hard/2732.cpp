class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int idx[1 << n];
        memset(idx, -1, sizeof(idx));
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (grid[i][j] * (1 << j));
            }
            idx[tmp] = i;
        }
        if (idx[0] != -1) return {idx[0]};
        for (int i = 0; i < (1 << n); i++) {
            if (idx[i] == -1) continue;
            for (int j = i + 1; j < (1 << n); j++) {
                if (idx[j] == -1) continue;
                if ((i & j) != 0) continue;
                int a = idx[i], b = idx[j];
                if (a > b) swap(a, b);
                return {a, b};
            }
        }
        return {};

    }
};