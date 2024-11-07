class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<bool> inf(n);
        for (auto i : initial) inf[i] = true;

        const int INF = 2e9;
        int mn = INF;
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (!inf[i]) continue;
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) tmp.push_back(j);
                graph[i][j] = graph[j][i] = 0;
            }

            queue<int> Q;
            vector<bool> vis(n);
            int got = 0;
            for (auto t : initial) if (t != i) {Q.emplace(t); vis[t] = true; got++;}
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (int j = 0; j < n; j++) {
                    if (!graph[now][j]) continue;
                    if (vis[j]) continue;
                    got++;
                    vis[j] = true;
                    Q.push(j);
                }
            }
            if (got < mn) {
                mn = got;
                idx = i;
            }

            for (auto t : tmp) graph[i][t] = graph[t][i] = 1;
        }

        return idx;
    }
};