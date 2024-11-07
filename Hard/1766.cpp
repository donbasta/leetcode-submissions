class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> coprimes(51);
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (__gcd(i, j) == 1) coprimes[i].push_back(j);
            }
        }
        int n = nums.size();
        vector<int> ret(n, -1);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<pair<int, int>>> cur(51);
        const function<void(int, int, int)> dfs = [&](int v, int p, int depth) -> void {
            int max_depth_anc = -1;
            for (auto e : coprimes[nums[v]]) {
                if (cur[e].empty()) continue;
                if (cur[e].back().second > max_depth_anc) {
                    max_depth_anc = cur[e].back().second;
                    ret[v] = cur[e].back().first;
                }
            }
            cur[nums[v]].emplace_back(v, depth);
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v, depth + 1);
            }
            cur[nums[v]].pop_back();
        };
        dfs(0, 0, 0);
        return ret;
    }
};