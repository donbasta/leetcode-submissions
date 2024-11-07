class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        using ll = long long;
        
        vector<vector<pair<int, ll>>> adj(n);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        
        const ll INF = 1e15;
        auto dijkstra = [&](int source) -> vector<ll> {
            vector<ll> ret(n, INF);
            ret[source] = 0;
            set<pair<ll, int>> se;
            se.emplace(0, source);
            while (!se.empty()) {
                auto now = *se.begin();
                se.erase(se.begin());
                int v = now.second;
                ll d = now.first;
                for (auto c : adj[v]) {
                    if (ret[c.first] > d + c.second) {
                        se.erase(make_pair(ret[c.first], c.first));
                        ret[c.first] = d + c.second;
                        se.emplace(ret[c.first], c.first);
                    }
                }
            }
            return ret;
        };

        vector<ll> D1 = dijkstra(0);
        vector<ll> D2 = dijkstra(n - 1);
        ll sp = D1[n - 1];
        
        // cout << sp << '\n';
        // for (int i = 0; i < n; i++) {
        //     cout << i << ' ' << D1[i] << ' ' << D2[i] << '\n';
        // }
    
        int E = edges.size();
        vector<bool> ans(E);
        
        if (sp == INF) return ans;
        
        for (int i = 0; i < E; i++) {
            if (D1[edges[i][0]] + edges[i][2] + D2[edges[i][1]] == sp) {
                ans[i] = true;
            }
            if (D1[edges[i][1]] + edges[i][2] + D2[edges[i][0]] == sp) {
                ans[i] = true;
            }
        }
        return ans;
    }
};