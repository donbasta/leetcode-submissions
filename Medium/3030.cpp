class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> avg(m, vector<int>(n, -1)), ret(m, vector<int>(n));

        const function<int(int, int)> get_average_3x3 = [&](int a, int b) -> int {
            int sum = 0;
            for (int i = a - 1; i <= a + 1; i++) for (int j = b - 1; j <= b + 1; j++) sum += image[i][j];
            return sum / 9;
        };

        const function<bool(int, int)> is_region_3x3 = [&](int a, int b) -> int {
            for (int i = a - 1; i <= a; i++) for (int j = b - 1; j <= b + 1; j++) if (abs(image[i][j] - image[i + 1][j]) > threshold) return false;
            for (int i = a - 1; i <= a + 1; i++) for (int j = b - 1; j <= b; j++) if (abs(image[i][j] - image[i][j + 1]) > threshold) return false;
            return true;
        };

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (is_region_3x3(i, j)) {
                    avg[i][j] = get_average_3x3(i, j);
                }
            }
        }
        ret = image;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt_region = 0, sum_region = 0;
                for (int ii = i - 1; ii <= i + 1; ii++) {
                    for (int jj = j - 1; jj <= j + 1; jj++) {
                        if (ii < 1 || ii >= m - 1 || jj < 1 || jj >= n - 1) continue;
                        if (avg[ii][jj] == -1) continue;
                        cnt_region++;
                        sum_region += avg[ii][jj];
                    }
                }
                if (cnt_region == 0) continue;
                ret[i][j] = sum_region / cnt_region;
            }
        }
        return ret;
    }
};