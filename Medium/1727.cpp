class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> bwh(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (j == m - 1) {
                    if (matrix[j][i] == 1) {
                        bwh[j][i] = j;
                    }
                } else {
                    if (matrix[j][i] == 0) continue;
                    if (matrix[j + 1][i] == 1) {
                        bwh[j][i] = bwh[j + 1][i];
                    } else {
                        bwh[j][i] = j;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> lmao;
            for (int j = 0; j < n; j++) {
                if (bwh[i][j] == -1) continue;
                lmao.push_back(bwh[i][j] - i + 1);
            }
            sort(lmao.begin(), lmao.end(), greater<>());
            int tmp = 0;
            int mn = m;
            for (int j = 0; j < lmao.size(); j++) {
                mn = min(mn, lmao[j]);
                tmp = max(tmp, (j + 1) * mn);
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};