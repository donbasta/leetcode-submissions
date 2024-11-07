class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n);

        const function<void(int)> dfs = [&](int v) -> void {
            vis[v] = true;
            for (int i = 0; i < n; i++) {
                if (i == v) continue;
                if (isConnected[v][i] == 0) continue;
                if (vis[i]) continue;
                dfs(i);
            }
        };

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            ans++;
            dfs(i);
        }
        return ans;
    }
};