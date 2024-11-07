class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> col(n), cur(n);
        int ans = -1;
        const function<void(int)> dfs = [&](int v) -> void {
            col[v] = 1;
            if (edges[v] != -1) {
                int u = edges[v];
                if (col[u] == 1) {
                    ans = max(ans, cur[v] - cur[u] + 1);
                } else if (col[u] == 0) {
                    cur[u] = cur[v] + 1;
                    dfs(u);
                }
            }
            col[v] = 2;
        };
        for (int i = 0; i < n; i++) {
            if (col[i] == 0) {
                cur[i] = 1;
                dfs(i);
            }
        }
        return ans;
    }
};