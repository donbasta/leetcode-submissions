class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cur = 0;
        int ans = 0;
        for (auto r : rungs) {
            ans += ((r - cur - 1) / dist);
            cur = r;
        }
        return ans;
    }
};