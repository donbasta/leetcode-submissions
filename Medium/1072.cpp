class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<vector<int>, int> cnt;
        for (int i = 0; i < m; i++) {
            vector<int> tmp = matrix[i];
            if (tmp[0] == 1) {
                for (int j = 0; j < n; j++) {
                    tmp[j] ^= 1;
                }
            }
            cnt[tmp]++;
        }
        int ans = 0;
        for (auto e : cnt) {
            ans = max(ans, e.second);
        }
        return ans;
    }
};