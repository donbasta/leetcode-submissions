class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int until = -2e9;
        for (auto e : timeSeries) {
            int bwh = max(e, until + 1);
            until = e + duration - 1;
            ans += (until - bwh + 1);
        }
        return ans;
    }
};