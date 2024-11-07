class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int pre[n][101];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 100; j++) {
                pre[i][j] = (i ? pre[i - 1][j] : 0) + (nums[i] == j);
            }
        }
        vector<int> ret(queries.size());
        int itr = 0;
        for (auto q : queries) {
            int tmp[101];
            for (int i = 1; i <= 100; i++) {
                tmp[i] = pre[q[1]][i] - (q[0] ? pre[q[0] - 1][i] : 0);
            }
            int prv = -1;
            int mn = INT_MAX;
            for (int i = 1; i <= 100; i++) {
                if (tmp[i] == 0) continue;
                if (prv != -1) {
                    mn = min(mn, i - prv);
                }
                prv = i;
            }
            if (mn == INT_MAX) ret[itr++] = -1;
            else ret[itr++] = mn;
        }
        return ret;
    }
};