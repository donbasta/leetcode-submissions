class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = 0;
        vector<int> pts[100000];
        int ori = 0;
        for (auto p : points) {
            int x = p[0] - location[0], y = p[1] - location[1];
            if (x == 0 && y == 0) {
                ori++;
            } else {
                pts[n++] = (vector<int>{x, y});
            }
        }
        if (n == 0) return ori;
        const double PI = acos(-1);
        auto get_angle = [&](vector<int> i1, vector<int> i2) -> double {
            if (i1 == i2) return 0;
            double x1 = i1[0], y1 = i1[1];
            double x2 = i2[0], y2 = i2[1];
            double cosine = (x1 * x2 + y1 * y2) / (hypot(x1, y1) * hypot(x2, y2));
            double sine = (x1 * y2 - x2 * y1) / (hypot(x1, y1) * hypot(x2, y2));

            double principal_angle = acos(cosine) * 180.0 / PI;
            if (sine >= 0) return principal_angle;
            else return (double)360 - principal_angle;
            return 0;
        };

        vector<int> zero_deg = {1, 0};
        double ang[n];
        for (int i = 0; i < n; i++) ang[i] = get_angle(zero_deg, pts[i]);
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b) -> bool {
            return ang[a] < ang[b];
        });

        int p1 = 0, p2 = 0, ans = 0;
        double eps = 1e-4;
        while (p1 < n) {
            while (p2 < p1 + n && get_angle(pts[idx[p1]], pts[idx[p2 % n]]) <= angle + eps) {
                p2++;
            }
            ans = max(ans, (p2 <= p1) ? (p2 + n - p1) : p2 - p1);
            p1++;
        }
        return ans + ori;
    }
};