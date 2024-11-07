class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        vector<unordered_map<int, int>> dist(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int norm = dx * dx + dy * dy;
                dist[i][norm]++, dist[j][norm]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (auto e : dist[i]) {
                ans += (e.second) * (e.second - 1);
            }
        }
        return ans;
    }
};