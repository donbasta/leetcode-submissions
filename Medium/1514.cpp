class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1], log10(succProb[i]));
            adj[edges[i][1]].emplace_back(edges[i][0], log10(succProb[i]));
        }

        priority_queue<pair<double, int>> pq;
        pq.emplace(0, start_node);
        vector<double> dis(n, -1e18);
        dis[start_node] = 0;

        while (!pq.empty()) {
            double val = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (val != dis[v]) continue;
            for (auto c : adj[v]) {
                if (dis[c.first] < dis[v] + c.second) {
                    dis[c.first] = dis[v] + c.second;
                    pq.emplace(dis[c.first], c.first);
                }
            }
        }

        if (dis[end_node] == -1e18) return 0;
        return pow(10, dis[end_node]);
    }
};