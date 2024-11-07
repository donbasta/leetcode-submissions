class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> tmp(n);
                for (int k = 0; k < n; k++) tmp[k] = grid[k][j];
                ans += tmp == grid[i];
            }
        }
        return ans;
    }
};