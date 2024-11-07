class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int ksor[n], tin[n], tout[n], par[n];
        par[0] = -1;
        vector<int> adj[n];
        int time = 0;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        const function<void(int, int)> dfs = [&](int v, int p) {
            int tmp = nums[v];
            tin[v] = time++;
            for (auto c : adj[v]) {
                if (c == p) continue;
                par[c] = v;
                dfs(c, v);
                tmp ^= ksor[c];
            }
            tout[v] = time++;
            ksor[v] = tmp;
        };
        dfs(0, 0);
        const function<bool(int, int)> is_parent = [&](int x, int y) -> bool {
            return tin[x] <= tin[y] && tout[x] >= tout[y];
        };
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a = edges[i][0], b = edges[i][1], c = edges[j][0], d = edges[j][1];
                if (par[a] == b) swap(a, b);
                if (par[c] == d) swap(c, d);
                vector<int> lmao;
                if (is_parent(b, c)) {
                    lmao = {ksor[d], ksor[b] ^ ksor[d], ksor[0] ^ ksor[b]};
                } else if (is_parent(d, a)) {
                    lmao = {ksor[b], ksor[d] ^ ksor[b], ksor[0] ^ ksor[d]};
                } else {
                    lmao = {ksor[b], ksor[d], ksor[0] ^ ksor[b] ^ ksor[d]};
                }
                sort(lmao.begin(), lmao.end());
                ans = min(ans, lmao[2] - lmao[0]);
            }
        }
        return ans;
    }
};