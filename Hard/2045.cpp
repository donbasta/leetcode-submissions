class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        set<pair<int, int>> se;
        const int INF = 2e9;
        vector<int> dis(n, INF), dis2(n, INF);
        se.emplace(0, 0);
        dis[0] = 0;
        set<int> to_end;
        while (!se.empty()) {
            auto val = se.begin()->first, v = se.begin()->second;
            se.erase(se.begin());
            if (val != dis[v] && val != dis2[v]) continue;
            int nw;
            if ((val / change) & 1) {
                nw = change * ((val / change) + 1) + time;
            } else {
                nw = val + time;
            }
            for (auto c : adj[v]) {
                if (nw < dis[c]) {
                    dis2[c] = dis[c];
                    dis[c] = nw;
                    se.emplace(dis[c], c);
                } else if (nw > dis[c] && nw < dis2[c]) {
                    dis2[c] = nw;
                    se.emplace(dis2[c], c);
                }
            }
        }
        if (dis2[n - 1] < INF) {
            return dis2[n - 1];
        }
        int tm = dis[n - 1];
        if ((tm / change) & 1) tm = change * ((tm / change) + 1) + time;
        else tm += time;
        if ((tm / change) & 1) tm = change * ((tm / change) + 1) + time;
        else tm += time;
        return tm;
    }
};

//hijau: 0..change-1, 2*change..3*change-1, ...
//merah: change..2*change-1, ...