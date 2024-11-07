class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> tmp(m, vector<char>(n, '.'));
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (box[i][j] == '#') {
                    cnt++;
                } else if (box[i][j] == '*') {
                    tmp[i][j] = '*';
                    for (int x = j - 1; x >= j - cnt; x--) {
                        tmp[i][x] = '#';
                    }
                    cnt = 0;
                } 
            }
            for (int j = n - 1; j >= n - cnt; j--) {
                tmp[i][j] = '#';
            }
        }
        vector<vector<char>> ret(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[j][m - 1 - i] = tmp[i][j];
            }
        }
        return ret;
    }
};