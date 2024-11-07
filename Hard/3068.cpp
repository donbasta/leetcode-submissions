class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> adj[n];
        for (auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        int col[n];
        col[0] = 0;
        const function<void(int, int)> dfs = [&](int v, int p) {
            for (auto c : adj[v]) {
                if (c == p) continue;
                col[c] = col[v] ^ 1;
                dfs(c, v);
            }
        };
        dfs(0, 0);
        long long tot = 0;
        vector<vector<int>> ve(2);
        for (int i = 0; i < n; i++) {
            tot += nums[i];
            ve[col[i]].push_back((nums[i] ^ k) - nums[i]);
        }
        long long mx[2][2];
        memset(mx, 0, sizeof(mx));
        const long long INF = 2e18;
        for (int i = 0; i < 2; i++) {
            sort(ve[i].begin(), ve[i].end(), greater<>());
            long long tmp = 0;
            mx[i][0] = 0;
            mx[i][1] = -INF;
            for (int j = 0; j < ve[i].size(); j++) {
                tmp += ve[i][j];
                mx[i][(j + 1) & 1] = max(mx[i][(j + 1) & 1], tmp);
            }
        }
        return tot + max(mx[0][0] + mx[1][0], mx[0][1] + mx[1][1]);
    }
};


        

