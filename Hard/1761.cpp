class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        bitset<401> adj[n + 1];
        int deg[n + 1];
        memset(deg, 0, sizeof(deg));
        for (auto e : edges) {
            adj[min(e[0], e[1])][max(e[0], e[1])] = true;
            deg[e[0]]++, deg[e[1]]++;
        }
        int ans = INT_MAX;
        for (auto e : edges) {
            bitset<401> tmp = adj[e[0]] & adj[e[1]];
            for (int i = tmp._Find_first(); i <= 400; i = tmp._Find_next(i)) {
                ans = min(ans, deg[e[0]] + deg[e[1]] + deg[i] - 6);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};