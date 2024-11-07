class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string x = equations[i][0], y = equations[i][1];
            double r = log(values[i]);
            adj[x].emplace_back(y, -r);
            adj[y].emplace_back(x, r);
        }
        vector<double> ret;
        for (auto q : queries) {
            string C = q[0], D = q[1];
            if (adj.find(C) == adj.end() || adj.find(D) == adj.end()) {
                ret.push_back(-1);
                continue;
            }
            map<string, double> ratio;
            queue<string> Q;
            Q.emplace(D);
            ratio[D] = 0.0;
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (auto c : adj[now]) {
                    if (ratio.find(c.first) != ratio.end()) continue;
                    ratio[c.first] = ratio[now] + c.second;
                    Q.emplace(c.first);
                }
            }
            if (ratio.find(C) == ratio.end()) {
                ret.push_back(-1);
            } else {
                ret.push_back(exp(ratio[C]));
            }
        }
        return ret;
    }
};