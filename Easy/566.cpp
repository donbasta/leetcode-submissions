class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<int> lmao(r * c);
        vector<vector<int>> ret(r, vector<int>(c));
        int x = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) lmao[x++] = mat[i][j];
        x = 0;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) ret[i][j] = lmao[x++];
        return ret;
    }
};