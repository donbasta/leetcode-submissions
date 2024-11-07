class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                tmp += grid[i][j];
            }
            if (tmp == n - 1) return i;
        }
        return -1;
    }
};