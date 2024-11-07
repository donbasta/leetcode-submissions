class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> isi(101, vector<double>(101));
        isi[0][0] = (double) poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double q = (isi[i][j] - 1.0) / 2.0;
                if (q > 0) {
                    isi[i + 1][j] += q;
                    isi[i + 1][j + 1] += q;
                }
            }
        }
        return min(1.0, isi[query_row][query_glass]);
    }
};