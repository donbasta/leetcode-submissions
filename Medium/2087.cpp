class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int x1 = startPos[0], y1 = startPos[1];
        int x2 = homePos[0], y2 = homePos[1];
        int ans = 0;
        if (x1 < x2) {
            while (x1 < x2) {
                ++x1;
                ans += rowCosts[x1];
            }
        } else {
            while (x1 > x2) {
                --x1;
                ans += rowCosts[x1];
            }
        }
        if (y1 < y2) {
            while (y1 < y2) {
                ++y1;
                ans += colCosts[y1];
            }
        } else {
            while (y1 > y2) {
                --y1;
                ans += colCosts[y1];
            }
        }
        return ans;
    }
};