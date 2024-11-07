class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int, int> mask_cnt;
        int tmp = 0;
        int n = parent.size();
        vector<pair<int, char>> adj[n];
        for (int i = 1; i < n; i++) {
            adj[parent[i]].emplace_back(i, s[i]);
        }
        const function<void(int)> dfs = [&](int v) {
            mask_cnt[tmp]++;
            for (auto c : adj[v]) {
                tmp ^= (1 << (c.second - 'a'));
                dfs(c.first);
                tmp ^= (1 << (c.second - 'a'));
            }
        };
        dfs(0);
        long long ans = 0;
        for (auto e : mask_cnt) {
            int mask = e.first;
            ans += (1ll * e.second * (e.second - 1));
            for (int i = 0; i < 26; i++) {
                int other = (1 << i) ^ mask;
                if (mask_cnt.find(other) == mask_cnt.end()) continue;
                ans += 1ll * e.second * mask_cnt[other];
            }
        }
        ans /= 2;
        return ans;
    }
};