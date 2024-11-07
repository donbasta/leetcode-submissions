class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        using ll = long long;
        vector<ll> cnt(24);
        for (auto h : hours) cnt[h % 24]++;
        ll ans = 0;
        for (int i = 0; i < 24; i++) {
            ans += cnt[i] * cnt[(24 - i) % 24];
        }
        ans -= cnt[0];
        ans -= cnt[12];
        ans /= 2;
        return ans;
    }
};