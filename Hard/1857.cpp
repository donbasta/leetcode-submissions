class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> color(n);
        bool adaCycle = false;
        vector<vector<int>> adj(n);
        vector<int> in(n);
        const function<bool(int)> dfs = [&](int v) -> bool {
            color[v] = 1;
            for (int u : adj[v]) {
                if (color[u] == 0) {
                    if (dfs(u))
                        return true;
                } else if (color[u] == 1) {
                    adaCycle = true;
                    return true;
                }
            }
            color[v] = 2;
            return false;
        };
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(v))
                break;
        }
        if (adaCycle) return -1;
        queue<int> Q;
        vector<vector<int>> most(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                Q.push(i);
                most[i][colors[i] - 'a'] = 1;
            }
        }
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (auto c : adj[now]) {
                int curCol = colors[c] - 'a';
                for (int i = 0; i < 26; i++) {
                    most[c][i] = max(most[c][i], most[now][i]);
                    if (i == curCol) most[c][i] = max(most[c][i], most[now][i] + 1);
                }
                --in[c];
                if (in[c] == 0) {
                    Q.push(c);
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                ans = max(ans, most[i][j]);
            }
        }
        return ans;
    }
};