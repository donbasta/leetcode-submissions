class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        const function<int(int)> fpar = [&](int x) -> int {
            return (x == par[x] ? x : par[x] = fpar(par[x]));
        };
        const function<void(int, int)> merge = [&](int x, int y) {
            x = fpar(x), y = fpar(y);
            if (x == y) return;
            par[y] = x;
            return;
        };

        vector<bool> ret;
        for (auto e : requests) {
            int x = e[0], y = e[1];
            int px = fpar(x), py = fpar(y);
            if (px == py) {
                ret.push_back(true);
                continue;
            }
            bool ok = true;
            for (auto r : restrictions) {
                int rx = fpar(r[0]), ry = fpar(r[1]);
                if ((rx == px && ry == py) || (rx == py && ry == px)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                merge(px, py);
            }
            ret.push_back(ok);
        }
        return ret;
    }
};