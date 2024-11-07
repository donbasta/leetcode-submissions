class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> from(n);
        for (auto e : edges) {
            from[e[0]].push_back(e[1]);

        }
        
        vector<vector<int>> ret(n);
        for (int i = 0; i < n; i++) {
            queue<int> Q;
            Q.emplace(i);
            vector<bool> vis(n);
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (auto c : from[now]) {
                    if (vis[c]) continue;
                    ret[c].push_back(i);
                    vis[c] = true;
                    Q.emplace(c);
                }
            }
        }
        return ret;
    }
};