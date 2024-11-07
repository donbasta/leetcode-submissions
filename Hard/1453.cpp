class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int ans = 1;

        auto get_center = [&](vector<int> p1, vector<int> p2, int radius) -> vector<pair<double, double>> {
            vector<pair<double, double>> ret;
            int dx = p1[0] - p2[0], dy = p1[1] - p2[1];
            if (dx * dx + dy * dy > r * r * 4) return ret;
            
            double mx = (double)(p1[0] + p2[0]) / 2, my = (double)(p1[1] + p2[1]) / 2;
            if (dx * dx + dy * dy == r * r * 4) {
                ret.emplace_back(mx, my);
                return ret;
            }
            
            double k = sqrt(((double)(r * r * 4 - dx * dx - dy * dy) / 4) / (dy * dy + dx * dx));
            ret.emplace_back(mx - dy * k, my + dx * k);
            ret.emplace_back(mx + dy * k, my - dx * k);
            return ret;
        };

        double eps = 1e-4;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<pair<double, double>> centers = get_center(darts[i], darts[j], r);
                for (auto c : centers) {
                    int tmp = 0;
                    for (int k = 0; k < n; k++) {
                        double dx = c.first - darts[k][0];
                        double dy = c.second - darts[k][1];
                        tmp += (dx * dx + dy * dy <= r * r + eps);
                    }
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};