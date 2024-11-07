class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto e : prerequisites) {
            adj[e[1]].push_back(e[0]);
        }
        // for (int i = 0; i < numCourses; i++) {
        //     cout << i << ':';
        //     for (auto e : adj[i]) cout << e << ' ';
        //     cout << '\n';
        // }
        vector<int> col(numCourses);
        const function<bool(int)> dfs = [&](int v) -> bool {
            col[v] = 1;
            for (auto c : adj[v]) {
                if (col[c] == 0) {
                    if (dfs(c)) return true;
                } else if (col[c] == 1) {
                    return true;
                }
            }
            col[v] = 2;
            return false;
        };
        vector<int> ret;
        for (int i = 0; i < numCourses; i++) {
            if (col[i] == 0) {
                if (dfs(i)) return ret;
            }
        }
        vector<bool> vis(numCourses);
        const function<void(int)> dfsTopo = [&](int v) -> void {
            vis[v] = true;
            for (auto c : adj[v]) {
                if (!vis[c]) dfsTopo(c);
            }
            ret.push_back(v);
        };
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) dfsTopo(i);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};