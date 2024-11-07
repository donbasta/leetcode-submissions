class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cnt = rows * cols;
        vector<vector<int>> ret;
        ret.push_back({rStart, cStart});
        int i = rStart, j = cStart + 1;
        int len = 3;
        cnt--;
        const function<bool(int, int)> ok = [&](int rr, int cc) -> bool {
            return (rr >= 0 && rr < rows && cc >= 0 && cc < cols);
        };
        while (cnt > 0) {
            if (ok(i, j)) {
                cnt--;
                ret.push_back({i, j});
            }
            for (int x = 0; x < len - 2; x++) {
                i++;
                if (ok(i, j)) {
                    cnt--;
                    ret.push_back({i, j});
                }
            }
            for (int x = 0; x < len - 1; x++) {
                j--;
                if (ok(i, j)) {
                    cnt--;
                    ret.push_back({i, j});
                }
            }
            for (int x = 0; x < len - 1; x++) {
                i--;
                if (ok(i, j)) {
                    cnt--;
                    ret.push_back({i, j});
                }
            }
            for (int x = 0; x < len - 1; x++) {
                j++;
                if (ok(i, j)) {
                    cnt--;
                    ret.push_back({i, j});
                }
            }
            j++;
            len += 2;
        }
        return ret;
    }
};