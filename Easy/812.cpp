class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        auto area = [&](vector<int>& x, vector<int>& y, vector<int>& z) -> int {
            return abs(x[0]*y[1]+y[0]*z[1]+z[0]*x[1] - x[1]*y[0]-y[1]*z[0]-z[1]*x[0]);
        };

        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
            ans = max(ans, area(points[i], points[j], points[k]));
        }
        return (double)ans / 2;
    }
};