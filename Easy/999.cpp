class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) if (board[i][j] == 'R') { r = i, c = j; break; }
        int ans = 0;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            while (nr >= 0 && nr <= 7 && nc >= 0 && nc <= 7 && board[nr][nc] == '.') { nr += dx[i], nc += dy[i]; }
            if (nr >= 0 && nr <= 7 && nc >= 0 && nc <= 7 && board[nr][nc] == 'p') ans++;
        }
        return ans;
    }
};