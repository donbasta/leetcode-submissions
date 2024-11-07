class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ret;
        for (int sum = 0; sum < m + n - 1; sum++) {
            for (int i = 0; i <= sum; i++) {
                if (sum & 1) {
                    if (i < m && (sum - i < n)) ret.push_back(mat[i][sum - i]); 
                } else {
                    if ((sum - i < m) && i < n) ret.push_back(mat[sum - i][i]);
                }
            }
        }
        return ret;
    }
};