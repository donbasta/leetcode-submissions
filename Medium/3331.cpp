class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& par, string s) {
        int n = par.size();
        vector<vector<int>> chd(n);
        vector<int> ans(n);
        vector<vector<int>> last(26);
        for (int i = 1; i < n; i++) {
            chd[par[i]].push_back(i);
        }

        vector<vector<int>> c2(n);
        function<void(int)> dfs = [&](int v) {
            if (!last[s[v] - 'a'].empty()) {
                c2[last[s[v] - 'a'].back()].push_back(v);
            } else {
                if (v != 0) {
                    c2[par[v]].push_back(v);
                }
            }
            last[s[v] - 'a'].push_back(v);
            for (auto c : chd[v]) {
                dfs(c);
            }
            last[s[v] - 'a'].pop_back();
        };

        function<void(int)> dfs2 = [&](int v) {
            ans[v]++;
            for (auto c : c2[v]) {
                dfs2(c);
                ans[v] += ans[c];
            }
        };
        
        dfs(0);
        dfs2(0);
        return ans;
    }
};