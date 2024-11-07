class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        using ll = long long;
        int n = costs.size();
        ll ans = 0;
        if (candidates >= n) {
            sort(costs.begin(), costs.end());
            for (int i = 0; i < k; i++) {
                ans += costs[i];
            }
            return ans;
        }
        int i1 = candidates - 1, i2 = n - candidates;
        set<pair<int, int>> s1, s2;
        bool taken[n];
        memset(taken, false, sizeof(taken));
        for (int i = 0; i <= i1; i++) s1.emplace(costs[i], i);
        for (int i = i2; i <= n - 1; i++) s2.emplace(costs[i], i);
        for (int i = 0; i < k; i++) {
            auto x1 = *s1.begin();
            auto x2 = *s2.begin();
            cout << x1.first << ' ' << x2.first << '\n';
            if (x1.first < x2.first) {
                ans += x1.first;
                taken[x1.second] = true;
                s1.erase(x1);
                i1++;
                while (i1 < n && taken[i1]) i1++;
                if (i1 < n) s1.emplace(costs[i1], i1);
            } else if (x1.first > x2.first) {
                ans += x2.first;
                taken[x2.second] = true;
                s2.erase(x2);
                i2--;
                while (i2 >= 0 && taken[i2]) i2--;
                if (i2 >= 0) s2.emplace(costs[i2], i2);
            } else if (x1.first == x2.first) {
                if (x1.second == x2.second) {
                    ans += x1.first;
                    taken[x1.second] = true;
                    i1++, i2--;
                    while (i1 < n && taken[i1]) i1++;
                    while (i2 >= 0 && taken[i2]) i2--;
                    s1.erase(x1), s2.erase(x2);
                    if (i1 < n) s1.emplace(costs[i1], i1);
                    if (i2 >= 0) s2.emplace(costs[i2], i2);
                } else {
                    ans += x1.first;
                    taken[x1.second] = true;
                    s1.erase(x1);
                    i1++;
                    while (i1 < n && taken[i1]) i1++;
                    if (i1 < n) s1.emplace(costs[i1], i1);
                }
            }
        }
        return ans;
    }
};