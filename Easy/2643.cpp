class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int idx = -1;
        int mx = -1;
        for (int i = 0; i < m; i++) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            if (cnt > mx) {
                mx = cnt;
                idx = i;
            }
        }
        return vector<int>{idx, mx};
    }
};