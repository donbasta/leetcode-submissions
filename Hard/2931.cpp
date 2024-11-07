class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        set<pair<int, pair<int, int>>> se;
        for (int i = 0; i < m; i++) {
            se.emplace(values[i][n - 1], make_pair(i, n - 1));
        }
        long long ans = 0;
        for (int i = 0; i < m * n; i++) {
            auto x = *se.begin();
            se.erase(se.begin());
            ans += 1ll * (i + 1) * x.first;
            if (x.second.second > 0) {
                se.emplace(values[x.second.first][x.second.second - 1], make_pair(x.second.first, x.second.second - 1));
            }
        }
        return ans;
    }
};