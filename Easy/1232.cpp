class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int a = coordinates[1][0] - coordinates[0][0];
        int b = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < n; i++) {
            int aa = coordinates[i][0] - coordinates[0][0];
            int bb = coordinates[i][1] - coordinates[0][1];
            if (aa * b != bb * a) return false;
        }
        return true;
    }
};