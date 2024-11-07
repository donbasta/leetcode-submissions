class Solution {
public:
    double xc, yc, r;
    double PI = acos(-1);
    Solution(double radius, double x_center, double y_center) {
        xc = x_center, yc = y_center, r = radius;
    }
    
    vector<double> randPoint() {
        double x = ((double)rand() / ((double)RAND_MAX) * r * 2) - r;
        double y = ((double)rand() / ((double)RAND_MAX) * r * 2) - r;
        while (x * x + y * y > r * r) {
            x = ((double)rand() / ((double)RAND_MAX) * r * 2) - r;
            y = ((double)rand() / ((double)RAND_MAX) * r * 2) - r;
        }
        return {xc + x, yc + y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */