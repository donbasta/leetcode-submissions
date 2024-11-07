class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int mx = 0;
        for (auto e : rectangles) {
            mx = max(mx, min(e[0], e[1]));
        }
        int ans = 0;
        for (auto e : rectangles) {
            if (min(e[0], e[1]) == mx) {
                ans++;
            }
        }
        return ans;
    }
};