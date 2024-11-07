class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        using ll = long long;
        int m = matrix.size();
        int n = matrix[0].size();
        ll ans = 0;
        int neg = 0;
        int mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += abs(matrix[i][j]);
                neg += (matrix[i][j] < 0);
                mn = min(mn, abs(matrix[i][j]));
            }
        }
        if ((mn == 0) || (neg % 2 == 0)) return ans;
        return ans - 2 * mn;
    }
};