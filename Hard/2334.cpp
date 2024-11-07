class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        int le[n], ri[n];
        memset(le, -1, sizeof(le));
        for (int i = 0; i < n; i++) ri[i] = n;
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            while (!ve.empty() && ve.back().first > nums[i]) {
                ri[ve.back().second] = i;
                ve.pop_back();
            }
            ve.emplace_back(nums[i], i);
        }
        ve.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!ve.empty() && ve.back().first > nums[i]) {
                le[ve.back().second] = i;
                ve.pop_back();
            }
            ve.emplace_back(nums[i], i);
        }
        for (int i = 0; i < n; i++) {
            int L = le[i] + 1, R = ri[i] - 1;
            int k = R - L + 1;
            if (1ll * k * nums[i] > threshold) {
                return k;
            }
        }
        return -1;
    }
};