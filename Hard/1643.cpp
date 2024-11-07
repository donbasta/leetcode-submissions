class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int r = destination[0], c = destination[1];
        vector<vector<int>> C(r + c + 1, vector<int>(r + c + 1));
        C[0][0] = 1;
        for (int i = 1; i <= r + c; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
        string ret;
        const function<void(int, int, int)> find = [&](int row, int col, int kth) -> void {
            if (row == 0) {
                for (int i = 0; i < col; i++) ret.push_back('H');
                return;
            }
            if (col == 0) {
                for (int i = 0; i < row; i++) ret.push_back('V');
                return;
            }
            int H_first = C[row + col - 1][col - 1];
            if (kth <= H_first) {
                ret.push_back('H');
                find(row, col - 1, kth);
            } else {
                ret.push_back('V');
                find(row - 1, col, kth - H_first);
            }
        };
        find(r, c, k);
        return ret;
    }
};