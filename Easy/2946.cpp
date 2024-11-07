class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int ch = ((i & 1) ? -k : k);
            bool ok = true;
            for (int j = 0; j < n; j++) {
                int nx = (j + ch) % n;
                if (nx < 0) nx += n;
                ok &= (mat[i][j] == mat[i][nx]);
            }
            if (!ok) return false;
        }
        return true;
    }
};