class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_map<int, bool> h, v;
        for (auto e : hFences) h[e - 1] = true;
        h[m - 1] = true;
        for (auto e : vFences) v[e - 1] = true;
        v[n - 1] = true;
        int nh = hFences.size(), nv = vFences.size();
        for (int i = 0; i < nh; i++) {
            for (int j = i + 1; j < nh; j++) {
                h[hFences[j] - hFences[i]] = true;
            }
            h[(m - hFences[i])] = true;
        }
        for (int i = 0; i < nv; i++) {
            for (int j = i + 1; j < nv; j++) {
                v[(vFences[j] - vFences[i])] = true;
            }
            v[(n - vFences[i])] = true;
        }
        int side = -1;
        for (auto e : h) {
            if (v.count(e.first)) side = max(side, e.first);
        }
        if (side == -1) return side;
        const int MOD = 1e9 + 7;
        return (1ll * side * side) % MOD;
    }
};