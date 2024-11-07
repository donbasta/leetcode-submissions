class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cur = 0;
        long long ans = 0;
        for (auto e : nums) {
            if (e == 0) cur++;
            else {
                ans += 1ll * cur * (cur + 1) / 2;
                cur = 0;
            }
        }
        ans += 1ll * cur * (cur + 1) / 2;
        return ans;
    }
};