class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int cur = points[0][0];
        int cnt = 1;
        int n = points.size();
        for (int i = 1; i < n; i++) {
            if (points[i][0] - cur > w) {
                cnt++;
                cur = points[i][0];
            }
        }
        return cnt;
    }
};