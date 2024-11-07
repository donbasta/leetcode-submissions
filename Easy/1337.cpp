class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ve;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (mat[i][j] == 1);
            }
            ve.emplace_back(tmp, i);
        }
        sort(ve.begin(), ve.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(ve[i].second);
        }
        return ret;
    }
};