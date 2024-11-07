class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pref(n, vector<int>(n));
        for (auto q : queries) {
            for (int i = q[0]; i <= q[2]; i++) {
                pref[i][q[1]]++;
                if (q[3] + 1 < n) pref[i][q[3] + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                pref[i][j] += pref[i][j - 1];
            }
        }
        return pref;
    }
};