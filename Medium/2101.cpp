class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long d2 = dx * dx + dy * dy;
                long long a = 1ll * bombs[i][2] * bombs[i][2];
                long long b = 1ll * bombs[j][2] * bombs[j][2];
                if (d2 <= a) {
                    adj[i].push_back(j);
                } 
                if (d2 <= b) {
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 1;

        const function<int(int)> bfs = [&](int v) -> int {
            vector<bool> vis(n);
            vis[v] = true;
            queue<int> Q;
            Q.push(v);
            int ret = 1;
            while (!Q.empty()) {
                int now = Q.front();
                Q.pop();
                for (auto c : adj[now]) {
                    if (vis[c]) continue;
                    vis[c] = true;
                    ret++;
                    Q.push(c);
                }
            }
            return ret;
        };

        for (int i = 0; i < n; i++) {
            ans = max(ans, bfs(i));
        }
        return ans;

    }
};