class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<pair<int, int>> DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> vis(m, vector<bool>(n));

        const function<bool(int, int, int)> find = [&](int i, int j, int idx) -> bool {
            if (idx == word.length()) return true;
            vis[i][j] = true;
            for (auto d : DIR) {
                int ni = i + d.first, nj = j + d.second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (vis[ni][nj]) continue;
                if (board[ni][nj] != word[idx]) continue;
                if (!find(ni, nj, idx + 1)) continue;
                else return true;
            }
            vis[i][j] = false;
            return false;
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != word[0]) continue;
                if (find(i, j, 1)) return true;
            }
        }

        return false;   
    }
};