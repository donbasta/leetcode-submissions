class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        using ll = long long;
        const ll MOD = 1e9 + 7;
        ll mn = 0, cur = 0, sb = 0;
        for (auto e : arr) {
            cur += e;
            sb = max(sb, cur - mn);
            mn = min(mn, cur);
        }
        if (k == 1) return sb % MOD;
        ll mp = 0, ms = 0;
        cur = 0;
        for (auto e : arr) {
            cur += e;
            mp = max(mp, cur);
        }
        reverse(arr.begin(), arr.end());
        cur = 0;
        for (auto e : arr) {
            cur += e;
            ms = max(ms, cur);
        }
        ll sum = accumulate(arr.begin(), arr.end(), 0ll);
        if (sum <= 0) {
            return max({sb, mp + ms}) % MOD;
        }
        return ((k - 2) * sum + mp + ms) % MOD;
    }
};