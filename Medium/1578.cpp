class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int tot = neededTime[0], mx = neededTime[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                tot += neededTime[i], mx = max(mx, neededTime[i]);
            } else {
                ans += (tot - mx);
                tot = mx = neededTime[i];
            }
        }
        ans += (tot - mx);
        return ans;
    }
};