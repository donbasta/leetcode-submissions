class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(dis, make_pair(i, j));
            }
        }
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        const function<int(int)> fpar = [&](int x) -> int {
            return (x == par[x] ? x : par[x] = fpar(par[x]));
        };
        const function<void(int, int)> merge = [&](int x, int y) {
            x = fpar(x), y = fpar(y);
            if (x == y) return;
            par[x] = y;
        };
        sort(edges.begin(), edges.end());
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < (int)edges.size(); i++) {
            if (fpar(edges[i].second.first) == fpar(edges[i].second.second)) {
                continue;
            }
            cnt++;
            ans += edges[i].first;
            merge(edges[i].second.first, edges[i].second.second);
            if (cnt == n - 1) {
                break;
            }
        }
        return ans;
    }
};