class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        set<int> unhappy;
        int m = n / 2;
        vector<vector<int>> pref(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                pref[i][preferences[i][j]] = j;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
                if (pref[x][u] < pref[x][y] && pref[u][x] < pref[u][v]) {
                    unhappy.insert(x), unhappy.insert(u);
                }
                if (pref[x][v] < pref[x][y] && pref[v][x] < pref[v][u]) {
                    unhappy.insert(x), unhappy.insert(v);
                }
                if (pref[y][u] < pref[y][x] && pref[u][y] < pref[u][v]) {
                    unhappy.insert(y), unhappy.insert(u);
                }
                if (pref[y][v] < pref[y][x] && pref[v][y] < pref[v][u]) {
                    unhappy.insert(y), unhappy.insert(v);
                }
            }
        }
        return unhappy.size();
    }
};