class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& itv) {
        int n = itv.size();
        int rem = 0;
        for (int i = 0; i < n; i++) {
            bool cov = false;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (itv[i][0] >= itv[j][0] && itv[i][1] <= itv[j][1]) {
                    cov = true;
                    break;
                }
            }
            rem += cov;
        }
        return n - rem;
    }
};