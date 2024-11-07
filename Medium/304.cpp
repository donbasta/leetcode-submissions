class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        pref.assign(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i][j] = matrix[i][j];
                if (i) pref[i][j] += pref[i - 1][j];
                if (j) pref[i][j] += pref[i][j - 1];
                if ((i > 0) && (j > 0)) pref[i][j] -= pref[i - 1][j - 1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = pref[row2][col2];
        if (col1) ret -= pref[row2][col1 - 1];
        if (row1) ret -= pref[row1 - 1][col2];
        if ((col1 > 0) && (row1 > 0)) ret += pref[row1 - 1][col1 - 1];
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */