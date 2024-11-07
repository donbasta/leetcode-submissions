class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        queue<int> Q;
        Q.push(source);
        vis[source] = true;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : adj[now]) {
                if (vis[c]) continue;
                vis[c] = true;
                Q.push(c);
            }
        }
        return vis[destination];
    }
};