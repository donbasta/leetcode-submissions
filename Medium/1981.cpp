class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        bitset<900> bs;
        bs[0] = true;
        int mn = 0;
        for (int i = 0; i < m; i++) {
            bitset<900> tmp;
            int cur_mn = INT_MAX;
            for (auto& j : mat[i]) {
                tmp = (tmp | (bs << j));
                cur_mn = min(cur_mn, j);
            }
            // for (int j = 0; j < n; j++) {
            //     tmp = (tmp | (bs << mat[i][j]));
            //     cur_mn = min(cur_mn, mat[i][j]);
            // }
            bs = tmp;
            mn += cur_mn;
        }
        int sz = bs.count();
        if (sz == 0) {
            return mn - target;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 900; i++) {
            if (!bs[i]) continue;
            if (i >= target) {
                ans = min(ans, i - target);
                break;
            }
            ans = target - i;
        }
        return ans;
    }
};