class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int mx = 0, mn = 0;
        int cur = 0;
        for (auto e : nums) {
            cur += e;
            int tmp_mn = cur - mx;
            int tmp_mx = cur - mn;
            mx = max(mx, cur);
            mn = min(mn, cur);
            ans = max(ans, abs(tmp_mn));
            ans = max(ans, abs(tmp_mx));
        }
        return ans;
    }
};