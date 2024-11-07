struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    int fpar(int x) {
        if (x == par[x]) return x;
        return par[x] = fpar(par[x]);
    }
    void merge(int x, int y) {
        int px = fpar(x), py = fpar(y);
        if (px == py) return;
        if (sz[px] < sz[py]) swap(px, py);
        par[py] = px;
        sz[px] += sz[py]; 
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);
        int MX = 1e5;
        vector<vector<int>> div(MX + 1);
        for (int i = 0; i < n; i++) {
            div[nums[i]].push_back(i);
            for (int k = 2; k * k <= nums[i]; k++) {
                if (nums[i] % k != 0) continue;
                div[k].push_back(i);
                if (k * k != nums[i]) div[nums[i] / k].push_back(i);
            }
        }
        for (int i = 2; i <= MX; i++) {
            if (div[i].empty()) continue;
            for (int k = 1; k < div[i].size(); k++) {
                dsu.merge(div[i][0], div[i][k]);
            }
        }
        return (dsu.sz[dsu.fpar(0)] == n);
    }
};