class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> owner;
        int par[n];
        iota(par, par + n, 0);
        function<int(int)> fpar = [&](int x) -> int {
            return x == par[x] ? x : par[x] = fpar(par[x]);
        };
        auto merge = [&](int x, int y) {
            x = fpar(x), y = fpar(y);
            if (x == y) return;
            par[x] = y; 
        };
        for (int i = 0; i < n; i++) {
            bool name = false;
            for (auto acc : accounts[i]) {
                if (!name) {
                    name = true;
                    continue;
                }
                if (owner.find(acc) == owner.end()) {
                    owner[acc] = i;
                } else {
                    merge(i, owner[acc]);
                }
            }
        }
        vector<string> tmp[n];
        // unordered_map<int, vector<string>> tmp;
        for (auto acc : owner) {
            tmp[fpar(acc.second)].push_back(acc.first);
        }
        vector<vector<string>> ret;
        for (int i = 0; i < n; i++) {
            if (fpar(i) != i) continue;
            sort(tmp[i].begin(), tmp[i].end());
            vector<string> buf;
            buf.push_back(accounts[i][0]);
            for (auto acc : tmp[i]) buf.push_back(acc);
            ret.push_back(buf);
        }
        return ret;
    }
};