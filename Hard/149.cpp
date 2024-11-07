class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = 2;
                long long dy = points[i][1] - points[j][1];
                long long dx = points[i][0] - points[j][0];
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    long long dy1 = points[k][1] - points[j][1];
                    long long dx1 = points[k][0] - points[j][0];
                    if (dy1 * dx == dx1 * dy) tmp++;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};