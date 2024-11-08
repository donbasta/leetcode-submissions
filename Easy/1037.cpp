class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0] - points[1][0], x2 = points[0][0] - points[2][0];
        int y1 = points[0][1] - points[1][1], y2 = points[0][1] - points[2][1];
        return x1 * y2 != y1 * x2;
    }
};