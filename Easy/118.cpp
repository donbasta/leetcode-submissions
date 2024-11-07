class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ve(numRows);
        ve[0] = {1};
        for (int i = 1; i < numRows; i++) {
            ve[i].resize(i + 1);
            ve[i][0] = ve[i][i] = 1;
            for (int j = 1; j < i; j++) {
                ve[i][j] = (ve[i - 1][j - 1] + ve[i - 1][j]);
            }
        }
        return ve;
    }
};