class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();
        using ll = long long;
        map<ll, int> mp;
        ll tot = accumulate(wall[0].begin(), wall[0].end(), 0ll);
        for (int i = 0; i < m; i++) {
            ll cur = 0;
            for (auto e : wall[i]) {
                cur += e;
                mp[cur]++;
            }
        }
        mp.erase(tot);
        int mx = 0;
        for (auto e : mp) {
            mx = max(mx, e.second);
        }
        return m - mx;
    }
};