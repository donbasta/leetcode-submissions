class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> par(n, -1);
        auto get_dis = [&](int v) -> vector<int> {
            vector<int> ret(n);
            queue<int> Q;
            ret[v] = 0;
            Q.push(v);
            par[v] = -1;
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (auto c : adj[now]) {
                    if (c == par[now]) continue;
                    par[c] = now;
                    ret[c] = ret[now] + 1;
                    Q.push(c);
                }
            }
            return ret;
        };
        vector<int> A = get_dis(0);
        int mx = -1, nd = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] > mx) {
                mx = A[i], nd = i;
            }
        }
        A = get_dis(nd);
        mx = -1; 
        int ndd = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] > mx) {
                mx = A[i], ndd = i;
            }
        }
        vector<int> paths;
        int cur = ndd;
        while (cur != nd) {
            paths.push_back(cur);
            cur = par[cur];
        }
        paths.push_back(cur);
        vector<int> ret;
        ret.push_back(paths[mx / 2]);
        if (mx & 1) ret.push_back(paths[mx / 2 + 1]);
        return ret;
    }
};