using ll = long long;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<ll> DP(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            ll a = (i < n - 1 ? DP[i + 1] : 0);
            ll b = q[i][0] + ((i + q[i][1] + 1 < n) ? DP[i + q[i][1] + 1] : 0);
            DP[i] = max(a, b);
        }
        return DP[0];
    }
};