class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int l = 1, r = 1e9;
        int mx;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
            if (mid - x >= k) {
                mx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        long long ret = 1ll * mx * (mx + 1) / 2;
        for (auto e : nums) {
            if (e <= mx) ret -= e;
        }
        return ret;
    }
};