class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 1e18;
        map<pair<int, int>, bool> ada;
        for (int i = 0; i < n; i++) {
            ada[make_pair(points[i][0], points[i][1])] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = j + 1; k < n; k++) {
                    if (k == i) continue;
                    int dx1 = points[j][0] - points[i][0];
                    int dy1 = points[j][1] - points[i][1];
                    int dx2 = points[k][0] - points[i][0];
                    int dy2 = points[k][1] - points[i][1];
                    long long cek = dx1 * dx2 + dy1 * dy2;
                    if (cek != 0) continue;
                    int nx = points[i][0] + dx1 + dx2;
                    int ny = points[i][1] + dy1 + dy2;
                    if (ada.find(make_pair(nx, ny)) == ada.end()) continue;
                    double area = abs(dx1 * dy2 - dy1 * dx2);
                    ans = min(ans, area);
                }
            }
        }
        if (ans == 1e18) {
            return 0;
        }
        return ans;
    }
};