class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int m = board.size();
        int n = board[0].size();
        auto valid = [&](int r, int c) -> bool {
            return r >= 0 && r < m && c >= 0 && c < n;
        };
        for (int i = 0; i < 8; i++) {
            int cx = rMove + dx[i];
            int cy = cMove + dy[i];
            int cnt = 0;
            while (valid(cx, cy) && board[cx][cy] != '.' && board[cx][cy] != color) {
                cx += dx[i], cy += dy[i], cnt++;
            }
            if (valid(cx, cy) && board[cx][cy] == color && cnt > 0) return true;
        }
        return false;
    }
};