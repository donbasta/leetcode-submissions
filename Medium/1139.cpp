class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = min(m, n); i >= 1; i--) {
            for (int j = 0; j + i - 1 < m; j++) {
                for (int k = 0; k + i - 1 < n; k++) {
                    if (i == 1) {
                        if (grid[j][k] == 1) return 1;
                        continue;
                    }
                    int nj = j, nk = k;
                    bool ok = true;
                    for (int x = 0; x < i - 1; x++) {
                        nk++;
                        if (grid[nj][nk] == 0) {ok = false;}
                    }
                    for (int x = 0; x < i - 1; x++) {
                        nj++;
                        if (grid[nj][nk] == 0) {ok = false;}
                    }
                    for (int x = 0; x < i - 1; x++) {
                        nk--;
                        if (grid[nj][nk] == 0) {ok = false;}
                    }
                    for (int x = 0; x < i - 1; x++) {
                        nj--;
                        if (grid[nj][nk] == 0) {ok = false;}
                    }
                    if (ok) return (i * i);
                }
            }
        }
        return 0;
    }
};