class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '0') continue;
                if (j < n - 1) {
                    if (matrix[i][j + 1] == '0') id[i][j] = j;
                    else id[i][j] = id[i][j + 1];
                } else {
                    id[i][j] = j;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mn = INT_MAX;
                for (int k = i; k < m; k++) {
                    if (matrix[k][j] == '0') break;
                    mn = min(mn, id[k][j]);
                    if (mn - j + 1 < k - i + 1) break;
                    int sisi = min((k - i + 1), (mn - j + 1));
                    ans = max(ans, sisi * sisi);
                }
            }
        }
        return ans;
    }
};