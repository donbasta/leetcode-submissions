class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int ans = INT_MAX;
        for (int T = 0; T < 2; T++) {
            if (T == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        board[i][j] ^= 1;
                    }
                }
            }

            map<vector<int>, vector<int>> mp;
            bool cant = false;
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (auto e : board[i]) {
                    cnt += (e == 1);
                }
                if ((cnt != (n / 2)) && (cnt != ((n + 1) / 2))) {
                    cant = true;
                    break;
                }
                mp[board[i]].push_back(i);
                if (mp.size() >= 3) {
                    cant = true;
                    break;
                }
            }
            if (cant) continue;
            if (mp.size() == 1) continue;
            for (auto e : mp) {
                int cnt = 0;
                for (auto x : e.first) cnt += (x == 1);
                if (cnt != e.second.size()) {
                    cant = true;
                    break;
                }
            }
            if (cant) continue;
            int mv = 0;
            if (n & 1) {
                vector<int> x = mp.begin()->first, y = mp.rbegin()->first;
                if (mp[x].size() < mp[y].size()) swap(x, y);
                for (int i = 0; i < n; i++) {
                    if ((i & 1) && (x[i] == 1)) mv++;
                }
                for (auto e : mp[x]) {
                    mv += (e & 1);
                }
            } else {
                vector<int> x = mp.begin()->first, y = mp.rbegin()->first;
                int p = 0, q = 0, r = 0, s = 0;
                for (int i = 0; i < n; i++) {
                    if ((i & 1) && (x[i] == 1)) p++;
                    if (!(i & 1) && (x[i] == 1)) q++;
                }
                for (auto e : mp[x]) {
                    r += (e & 1);
                    s += !(e & 1);
                }
                mv = min(p, q) + min(r, s);
            }
            ans = min(ans, mv);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};