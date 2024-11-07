class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res = matrix;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int mx = -1;
            for (int j = 0; j < m; j++) {
                mx = max(mx, res[j][i]);
            }
            for (int j = 0; j < m; j++) {
                if (res[j][i] == -1) res[j][i] = mx;
            }
        }
        return res;
    }
};