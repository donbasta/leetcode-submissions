class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adj;
        map<string, int> out;
        for (auto e : tickets) {
            adj[e[0]].push_back(e[1]);
            out[e[0]]++;
        }
        for (auto e : adj) {
            sort(adj[e.first].begin(), adj[e.first].end(), greater<>());
        }
        vector<string> route;
        const function<void(string)> dfs = [&](string v) {
            while (out[v]) {   
                string next = adj[v][--out[v]];
                dfs(next);
            }
            route.push_back(v);
        };
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};