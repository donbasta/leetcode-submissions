class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        using ll = long long;
        map<ll, vector<int>> mp;
        for (auto m : meetings) {
            mp[m[0]].push_back(m[1] - m[0]);
        }
        set<int> avail;
        for (int i = 0; i < n; i++) avail.insert(i);
        vector<int> cnt(n);
        set<pair<ll, int>> pending;

        for (auto e : mp) {
            ll now = e.first;
            int sz = e.second.size();
            for (int i = sz - 1; i >= 0; i--) {
                if (e.second[i] <= 0) {
                    avail.insert(-e.second[i]);
                } else {
                    pending.emplace(now, e.second[i]);

                }
            }
            while (!avail.empty() & !pending.empty()) {
                auto x = *pending.begin();
                pending.erase(pending.begin());
                auto y = *avail.begin();
                avail.erase(avail.begin());
                // cout << x.first << ' ' << x.second << ' ' << now << ' ' << y << '\n';
                cnt[y]++;
                mp[now + x.second].push_back(-y);
            }
        }

        int idx = 0;
        int mx = cnt[0];
        for (int i = 1; i < n; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                idx = i;
            }
        }
        return idx;
    }
};