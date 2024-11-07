class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        int ans = INT_MAX;
        for (int i = 0; i <= k; i++) {
            vector<int> tmp(n, INT_MAX);
            for (auto e : flights) {
                if (cost[e[0]] == INT_MAX) continue;
                tmp[e[1]] = min(tmp[e[1]], cost[e[0]] + e[2]);
            }
            cost = tmp;
            ans = min(ans, cost[dst]);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};