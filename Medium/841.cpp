class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        const function<void(int)> dfs = [&](int v) -> void {
            vis[v] = true;
            for (auto e : rooms[v]) {
                if (vis[e]) continue;
                dfs(e);
            }
        };
        dfs(0);
        for (auto e : vis) {
            if (!e) return false;
        }
        return true;
    }
};