class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> results;
        for (auto q : queries) {
            int ans = 0;
            for (auto p : points) {
                int dx = abs(p[0] - q[0]);
                int dy = abs(p[1] - q[1]);
                int squaredDistance = dx * dx + dy * dy;
                ans += (squaredDistance <= q[2] * q[2]);
            }
            results.push_back(ans);
        }
        return results;
    }
};