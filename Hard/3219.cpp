class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        using ll = long long;
        vector<vector<int>> C(1001, vector<int>(2));
        for (auto h : horizontalCut) {
            C[h][0]++;
        }
        for (auto v : verticalCut) {
            C[v][1]++;
        }
        ll H = 0, V = 0;
        ll ans = 0;
        for (int i = 1000; i >= 0; i--) {
            ans += 1ll * i * (V + 1) * C[i][0];
            ans += 1ll * i * (H + 1) * C[i][1];
            ans += 1ll * i * C[i][0] * C[i][1];
            H += C[i][0];
            V += C[i][1];
        }
        return ans;
    }
};