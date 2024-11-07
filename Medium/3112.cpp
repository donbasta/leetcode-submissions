class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        using ll = long long;
        const ll INF = 1e18;
        vector<ll> dis(n, INF); 
        dis[0] = 0;
        set<pair<ll, int>> se;
        se.emplace(dis[0], 0);
        
        vector<int> ret(n, -1);
        while (!se.empty()) {
            auto now = *se.begin();
            se.erase(se.begin());
            ll dv = now.first, v = now.second;
            assert (dv < disappear[v]);
            ret[v] = dv;
            for (auto nx : adj[v]) {
                if ((dv + nx.second < dis[nx.first]) && (dv + nx.second < 1ll * disappear[nx.first])) {
                    se.erase(make_pair(dis[nx.first], nx.first));
                    dis[nx.first] = dv + nx.second;
                    se.emplace(dis[nx.first], nx.first);
                }
            }
        }
        return ret;
    }
};