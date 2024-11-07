class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> longestKebawah(m, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            int start = -1;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == '0') {
                    if (start == -1) continue;
                    else {
                        for (int k = start; k < j; k++) {
                            longestKebawah[k][i] = j - 1;
                        }
                        start = -1;
                    }
                } else {
                    if (start == -1) {
                        start = j;
                    }
                }
            }
            if (start != -1) {
                for (int k = start; k < m; k++) {
                    longestKebawah[k][i] = m - 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curMin = 1000;
                for (int k = j; k < n; k++) {
                    if (longestKebawah[i][k] == -1) break;
                    curMin = min(curMin, longestKebawah[i][k] - i + 1);
                    ans = max(ans, (k - j + 1) * curMin);
                }
            }
        }
        return ans;
    }
};