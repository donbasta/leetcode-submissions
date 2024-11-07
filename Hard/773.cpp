class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> Q;
        map<vector<vector<int>>, int> dis;
        Q.push(board);
        dis[board] = 0;

        vector<vector<int>> solved = {{1, 2, 3}, {4, 5, 0}};

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        auto adj = [&](vector<vector<int>> T) -> vector<vector<vector<int>>> {
            int x = -1, y = -1;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (T[i][j] == 0) {
                        x = i, y = j;
                        break;
                    }
                }
            }
            vector<vector<vector<int>>> ret;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= 2 || ny < 0 || ny >= 3) continue;
                swap(T[x][y], T[nx][ny]);
                ret.push_back(T);
                swap(T[x][y], T[nx][ny]);
            }
            return ret;
        };

        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : adj(now)) {
                if (dis.count(c)) continue;
                dis[c] = dis[now] + 1;
                if (c == solved) {
                    return dis[c];
                }
                Q.push(c);
            }
        }

        if (!dis.count(solved)) {
            return -1;
        }
        return dis[solved];
    }
};