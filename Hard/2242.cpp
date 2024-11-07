class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        set<pair<int, int>> adj[n];
        for (auto e : edges) {
            adj[e[0]].emplace(scores[e[1]], e[1]);
            adj[e[1]].emplace(scores[e[0]], e[0]);
        }
        int ans = -1;
        for (auto e : edges) {
            if (adj[e[0]].size() == 1 || adj[e[1]].size() == 1) continue;

            adj[e[0]].erase(make_pair(scores[e[1]], e[1]));
            adj[e[1]].erase(make_pair(scores[e[0]], e[0]));
            auto p0 = adj[e[0]].end(); --p0;
            auto p1 = adj[e[1]].end(); --p1;
            int tmp = scores[e[0]] + scores[e[1]];
            if (p0->second != p1->second) {
                ans = max(ans, tmp + p0->first + p1->first);
            } else {
                int lmao = -1;
                if (p0 != adj[e[0]].begin()) {
                    auto q0 = p0; --q0;
                    lmao = max(lmao, q0->first + p1->first);
                }
                if (p1 != adj[e[1]].begin()) {
                    auto q1 = p1; --q1;
                    lmao = max(lmao, q1->first + p0->first);
                }
                if (lmao != -1) {
                    ans = max(ans, tmp + lmao);
                }
            }
            adj[e[0]].emplace(scores[e[1]], e[1]);
            adj[e[1]].emplace(scores[e[0]], e[0]);
        }
        return ans;
    }
};