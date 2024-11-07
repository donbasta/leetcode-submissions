class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        using ll = long long;
        vector<pair<ll, ll>> ve;
        int n = damage.size();
        for (int i = 0; i < n; i++) {
            ve.emplace_back(damage[i], (health[i] + power - 1) / power);
        }
        sort(ve.begin(), ve.end(), [&](pair<ll, ll> A, pair<ll, ll> B) -> bool {
            return A.first * B.second < B.first * A.second;
        });
        ll ans = 0;
        ll dmg = 0;
        for (int i = 0; i < n; i++) {
            dmg += ve[i].first;
            ans += ve[i].second * dmg;
        }
        return ans;
    }
};