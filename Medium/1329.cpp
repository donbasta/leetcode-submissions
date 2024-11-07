class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<pair<int, int>> startDiag;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) startDiag.emplace_back(i, 0);
        for (int i = 1; i < n; i++) startDiag.emplace_back(0, i);
        for (auto s : startDiag) {
            vector<pair<int, int>> positions;
            vector<int> values;
            int x = s.first, y = s.second;
            while (x < m && y < n) {
                positions.emplace_back(x, y);
                values.emplace_back(mat[x][y]);
                x++, y++;
            }
            sort(values.begin(), values.end());
            for (int i = 0; i < values.size(); i++) {
                mat[positions[i].first][positions[i].second] = values[i];
            }
        }
        return mat;
    }
};