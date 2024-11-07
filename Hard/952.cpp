struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int fpar(int v) {
        if (v == p[v]) return v;
        return p[v] = fpar(p[v]);
    }
    void merge(int x, int y) {
        x = fpar(x), y = fpar(y);
        if (x == y) return;
        p[x] = y;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        set<int> primes;
        int n = nums.size();
        vector<vector<int>> pr(n);
        for (int k = 0; k < n; k++) {
            int f = nums[k];
            for (int i = 2; i * i <= f; i++) {
                if (f % i == 0) {
                    primes.insert(i);
                    pr[k].push_back(i);
                    while (f % i == 0) f /= i;
                }
            }
            if (f > 1) {
                primes.insert(f);
                pr[k].push_back(f);
            }
        }
        int lmao = nums.size();
        map<int, int> mp;
        for (auto e : primes) mp[e] = lmao++;
        DSU dsu(lmao);
        for (int i = 0; i < n; i++) {
            for (auto j : pr[i]) {
                dsu.merge(i, mp[j]);
            }
        }
        map<int, int> sz;
        for (int i = 0; i < n; i++) {
            sz[dsu.fpar(i)]++;
        }
        int mx = 1;
        for (auto e : sz) {
            mx = max(mx, e.second);
        }
        return mx;
    }
};