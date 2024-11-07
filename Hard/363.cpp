class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size(); 

        vector<vector<int>> col(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col[i][j] = (j ? col[i][j - 1] : 0) + matrix[j][i];
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                set<int> se;
                se.insert(0);
                int cur = 0;
                for (int kk = 0; kk < n; kk++) {
                    int now = cur + (col[kk][j] - (i ? col[kk][i - 1] : 0));
                    //now - elem <= k --> elem >= now - k;
                    auto itr = se.lower_bound(now - k);
                    if (itr != se.end()) ans = max(ans, now - *itr);
                    se.insert(now);
                    cur = now;
                }
            }
        }
        return ans;
    }
};