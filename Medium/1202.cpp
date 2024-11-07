class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();

        vector<vector<int>> adj(n);
        for (auto e : pairs) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);

        const function<void(int, vector<int>&)> dfs = [&](int v, vector<int>& ind) -> void {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                ind.push_back(c);
                vis[c] = true;
                dfs(c, ind);
            }
        };

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vector<int> indices;
            indices.push_back(i);
            vis[i] = true;
            dfs(i, indices);
            sort(indices.begin(), indices.end());
            string tmp;
            for (auto e : indices) tmp.push_back(s[e]);
            sort(tmp.begin(), tmp.end());
            int idx = 0;
            for (auto e : indices) s[e] = tmp[idx++];
        }

        return s;
    }
};