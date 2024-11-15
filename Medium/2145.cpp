class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        using ll = long long;
        ll cur = 0;
        ll mx = 0, mn = 0;
        for (auto d : differences) {
            cur += d;
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        ll d1 = upper - lower;
        ll d2 = mx - mn;
        if (d2 > d1) return 0;
        return d1 - d2 + 1;
    }
};