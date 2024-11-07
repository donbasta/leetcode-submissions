class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> in(n);
        vector<vector<vector<int>>> paths(n);

        for (int i = 0; i < n; i++) {
            for (auto e : graph[i]) {
                in[e]++;
            }
        }

        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                Q.emplace(i);
                paths[i] = {{i}};
            }
        }

        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto e : graph[now]) {
                for (auto path : paths[now]) {
                    vector<int> tmp = path;
                    tmp.emplace_back(e);
                    paths[e].emplace_back(tmp);
                }
                --in[e];
                if (in[e] == 0) {
                    Q.emplace(e);
                }
            }
        }

        set<vector<int>> se;
        for (auto path : paths[n - 1]) {
            vector<int> tmp;
            bool ok = false;
            for (int i = path.size() - 1; i >= 0; --i) {
                tmp.push_back(path[i]);
                if (path[i] == 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                reverse(tmp.begin(), tmp.end());
                se.insert(tmp);
            }
        }

        return vector<vector<int>>(se.begin(), se.end());
    }
};