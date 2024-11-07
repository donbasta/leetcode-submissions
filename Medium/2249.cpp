class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int sz = circles.size();
        int ans = 0;
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (int k = 0; k < sz; k++) {
                    int dx = (circles[k][0] - i), dy = (circles[k][1] - j);
                    if (dx * dx + dy * dy <= circles[k][2] * circles[k][2]) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};