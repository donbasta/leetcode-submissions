class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        ll mx = -1;
        ll ret = 0;
        for (int i = 0; i < n - 1; i++) {
            mx = max(mx, 1ll * nums[i]);
            ret += mx;
        }
        return ret;
    }
};