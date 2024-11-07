class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        int ans = 0;
        for (auto e : houses) {
            int x = lower_bound(heaters.begin(), heaters.end(), e) - heaters.begin();
            int tmp = INT_MAX;
            if (x < n) {
                tmp = min(tmp, heaters[x] - e);
            }
            if (x > 0) {
                tmp = min(tmp, e - heaters[x - 1]);
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};