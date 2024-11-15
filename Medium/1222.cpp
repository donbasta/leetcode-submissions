class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int kr = king[0], kc = king[1];
        vector<vector<int>> ret;
        int gr[8][8];
        memset(gr, 0, sizeof(gr));
        gr[kr][kc] = 1;
        for (auto q : queens) gr[q[0]][q[1]] = 2;
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
        for (auto q : queens) {
            bool found = false;
            for (int j = 0; j < 8; j++) {
                int qr = q[0] + dx[j], qc = q[1] + dy[j];
                while (qr >= 0 && qr < 8 && qc >= 0 && qc < 8 && gr[qr][qc] == 0) {
                    qr += dx[j], qc += dy[j];
                }
                if (qr >= 0 && qr < 8 && qc >= 0 && qc < 8 && gr[qr][qc] == 1) {
                    ret.push_back(q);
                    found = true;
                }
                if (found) break;
            }
        }
        return ret;
    }
};