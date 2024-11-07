class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diag = 0;
        int ret = 0;
        for (auto e : dimensions) {
            int tmp = e[0] * e[0] + e[1] * e[1];
            if (tmp > diag) {
                diag = tmp;
                ret = e[0] * e[1];
            } else if (tmp == diag) {
                ret = max(ret, e[0] * e[1]);
            }
        }
        return ret;
    }
};