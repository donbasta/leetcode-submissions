class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        const int MX_TIME = 1e5;
        vector<vector<int>> ve[MX_TIME + 1];
        // vector<vector<vector<int>>> ve(MX_TIME + 1);
        for (auto e : meetings) {
            ve[e[2]].push_back({e[0], e[1]});
        }
        bool know[n];
        memset(know, false, sizeof(know));
        know[0] = true;
        know[firstPerson] = true;
        for (int i = 1; i <= MX_TIME; i++) {
            if (ve[i].empty()) continue;
            queue<int> Q;
            unordered_map<int, vector<int>> adj;
            unordered_map<int, bool> vis;
            for (auto e : ve[i]) {
                for (int j = 0; j < 2; j++) {
                    adj[e[j]].push_back(e[1 - j]);
                    if (know[e[j]]) {
                        if (!vis[e[j]]) {
                            Q.emplace(e[j]);
                            vis[e[j]] = true;
                        }
                    }
                }
            }
            while (!Q.empty()) {
                int now = Q.front();
                Q.pop();
                for (auto c : adj[now]) {
                    if (vis[c]) continue;
                    vis[c] = true;
                    know[c] = true;
                    Q.push(c);
                }
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (know[i]) ret.push_back(i);
        }
        return ret;
    }
};