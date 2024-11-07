class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] + matrix[i][j] - pref[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) { //from row i to row j
                unordered_map<int, int> umap;
                umap[0]++;
                int curTot = 0;
                for (int k = 0; k < n; k++) {
                    int tmp = pref[j][k + 1] - pref[j][k] - pref[i - 1][k + 1] + pref[i - 1][k];
                    curTot += tmp;
                    ans += umap[curTot - target];
                    umap[curTot]++;
                }
            }
        }
        return ans;
    }
};