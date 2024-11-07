class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        set<pair<int, int>> gue;
        for (auto e : guesses) {
            gue.emplace(e[0], e[1]);
        }
        
        int num_guesses = 0;
        const function<void(int, int)> dfsFirst = [&](int v, int p) -> void {
            for (auto c : adj[v]) {
                if (c == p) continue;
                if (gue.count(make_pair(v, c))) num_guesses++;
                dfsFirst(c, v);
            }
        };
        dfsFirst(0, 0);
        
        int ans = 0;
        const function<void(int, int)> dfsReroot = [&](int v, int p) -> void {
            if (num_guesses >= k) {
                ans++;
            }
            for (auto c : adj[v]) {
                if (c == p) continue;
                if (gue.count(make_pair(c, v))) num_guesses++;
                if (gue.count(make_pair(v, c))) num_guesses--;
                dfsReroot(c, v);
                if (gue.count(make_pair(c, v))) num_guesses--;
                if (gue.count(make_pair(v, c))) num_guesses++;
                
            }
        };
        dfsReroot(0, 0);
        return ans;
        
    }
};