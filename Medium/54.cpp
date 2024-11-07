class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<int> ans;
        int px = 0, py = 0;
        int idxDir = 0;
        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[px][py]);
            vis[px][py] = true;
            int nx = px + dir[idxDir].first;
            int ny = py + dir[idxDir].second;
            bool cant = false;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cant = true;
            } else if (vis[nx][ny]) {
                cant = true;
            }
            if (cant) {
                idxDir = (idxDir + 1) % 4;
            }
            px = px + dir[idxDir].first;
            py = py + dir[idxDir].second;
        }
        return ans;
    }
};