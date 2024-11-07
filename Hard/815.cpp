class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int mx = -1;
        int tot = 0;
        for (auto r : routes) {
            tot += r.size();
            for (auto e : r) {
                mx = max(mx, e);
            }
        }
        if (target > mx) return -1;
        int cnt = 0;
        vector<vector<int>> indices(mx + 1);
        int sz = routes.size();
        vector<vector<pair<int, int>>> adj(sz + mx + tot + 5);
        for (int i = 0; i < sz; i++) {
            for (auto e : routes[i]) {
                indices[e].push_back(cnt);
                adj[i].emplace_back(sz + e, 1);
                adj[sz + e].emplace_back(i, 0);
                adj[i].emplace_back(sz + mx + cnt + 1, 0);
                adj[sz + mx + cnt + 1].emplace_back(i, 0);
                cnt++;
            }
        }
        deque<int> Q;
        const int INF = 1e9;
        vector<int> dis(sz + mx + tot + 5, INF);
        for (auto e : indices[source]) {
            Q.push_back(sz + mx + e + 1);
            dis[sz + mx + e + 1] = 0;
        }
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop_front();
            for (auto c : adj[now]) {
                if (dis[now] + c.second < dis[c.first]) {
                    dis[c.first] = dis[now] + c.second;
                    if (c.second == 1) {
                        Q.push_back(c.first);
                    } else {
                        Q.push_front(c.first);
                    }
                }
            }
        }
        int mn = INF;
        for (auto e : indices[target]) {
            mn = min(mn, dis[sz + mx + e + 1]);
        }
        if (mn == INF) {
            return -1;
        }
        return mn + 1;
    }
};