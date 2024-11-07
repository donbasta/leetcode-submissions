class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for (int i = 0; i < n; i++) {
            if (col[i] != -1) continue;
            col[i] = 0;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (auto c : graph[now]) {
                    if (col[c] != -1) {
                        if (col[c] == col[now]) return false;
                    } else {
                        col[c] = col[now] ^ 1;
                        Q.push(c);
                    }
                }
            }
        }
        return true;
    }
};