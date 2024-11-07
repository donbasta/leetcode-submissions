using ll = long long;
class Solution {
public:
    vector<ll> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<ll> ret(n);
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        multiset<int> se[n];
        const function<void(int, int)> dfs = [&](int v, int p) {
            se[v].insert(cost[v]);
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                if (se[v].size() < se[c].size()) {
                    se[v].swap(se[c]);
                }
                for (auto e : se[c]) se[v].insert(e);
            }
            if (se[v].size() < 3) {
                ret[v] = 1;
            } else {
                ll mx = 0, tmp = 1;
                auto ptr = se[v].begin();
                vector<ll> pref(4), suf(4);
                pref[0] = suf[0] = 1;
                for (int i = 0; i < 3; i++) {
                    tmp *= *ptr;
                    pref[i + 1] = tmp;
                    ++ptr;
                }    
                tmp = 1;
                auto ptr_rev = se[v].rbegin();
                for (int i = 0; i < 3; i++) {
                    tmp *= *ptr_rev;
                    suf[i + 1] = tmp;
                    ++ptr_rev;
                }
                mx = max({mx, pref[0] * suf[3], pref[1] * suf[2], pref[2] * suf[1], pref[3] * suf[0]});
                ret[v] = mx;
            }
        };
        dfs(0, 0);
        return ret;
    }
};