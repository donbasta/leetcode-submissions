class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++) ans += mat[i][i];
        for (int i = 0; i < n; i++) ans += mat[i][n - 1 - i];
        if (n & 1) {
            int mid = (n / 2);
            ans -= mat[mid][mid];
        }
        return ans;
    }
};