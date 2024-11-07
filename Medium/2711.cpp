class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            int cx = 0, cy = i;
            set<int> se;
            while (cx < m && cy < n) {
                ret[cx][cy] += se.size();
                se.insert(grid[cx][cy]);
                cx++, cy++;
            }
            cx--, cy--;
            se.clear();
            while (cx >= 0 && cy >= 0) {
                ret[cx][cy] -= se.size();
                ret[cx][cy] = abs(ret[cx][cy]);
                se.insert(grid[cx][cy]);
                cx--, cy--;
            }
        }
        for (int i = 1; i < m; i++) {
            int cx = i, cy = 0;
            set<int> se;
            while (cx < m && cy < n) {
                ret[cx][cy] += se.size();
                se.insert(grid[cx][cy]);
                cx++, cy++;
            }
            cx--, cy--;
            se.clear();
            while (cx >= 0 && cy >= 0) {
                ret[cx][cy] -= se.size();
                ret[cx][cy] = abs(ret[cx][cy]);
                se.insert(grid[cx][cy]);
                cx--, cy--;
            }
        }
        return ret;
    }
};