class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> ada(n, vector<bool>(n));
        vector<int> deg(n);
        for (auto r : roads) {
            ada[r[0]][r[1]] = ada[r[1]][r[0]] = true;
            deg[r[0]]++, deg[r[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tot = deg[i] + deg[j];
                if (ada[i][j] || ada[j][i]) tot--;
                ans = max(ans, tot);
            }
        }
        return ans;
    }
};