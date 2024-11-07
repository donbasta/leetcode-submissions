class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> mr(m, INT_MAX), mc(n, INT_MIN);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mr[i] = min(mr[i], matrix[i][j]);
                mc[j] = max(mc[j], matrix[i][j]);
            }
        }
        vector<int> ret;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mr[i] == matrix[i][j] && mc[j] == matrix[i][j]) {
                    ret.push_back(matrix[i][j]);
                }
            }    
        }
        assert(ret.size() <= 1);
        return ret;
    }
};