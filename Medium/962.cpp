class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) ve.emplace_back(nums[i], i);
        sort(ve.begin(), ve.end());
        int L = n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (L != n) {
                ans = max(ans, ve[i].second - L);
            }
            L = min(L, ve[i].second);
        }
        return ans;
    }
};