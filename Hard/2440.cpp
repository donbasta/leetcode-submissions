class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> adj[n];
        int sum[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        const function<void(int, int)> dfs = [&](int v, int par) -> void {
            sum[v] = nums[v];
            for (auto c : adj[v]) {
                if (c == par) continue;
                dfs(c, v);
                sum[v] += sum[c];
            }
        };
        dfs(0, -1);
        int tot = sum[0];
        const function<void(int, int, int, vector<int>&)> dfs1 = [&](int v, int par, int ss, vector<int>& cnt) -> void {
            for (auto c : adj[v]) {
                if (c == par) continue;
                dfs1(c, v, ss, cnt);
                cnt[v] += cnt[c];
            }
            if (sum[v] == ss * (cnt[v] + 1)) {
                cnt[v]++;
            }
        };
        for (int i = n; i >= 2; i--) {
            if (tot % i != 0) continue;
            int sum_each_comp = tot / i;
            vector<int> cnt(n);
            dfs1(0, -1, sum_each_comp, cnt);
            if (cnt[0] == i) return (i - 1);
        }
        return 0;
    }
};