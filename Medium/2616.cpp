class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort (nums.begin(), nums.end());
        vector<int> diff;
        for (int i = 1; i < nums.size(); i++) {
            diff.push_back(nums[i] - nums[i - 1]);
        }
        int lo = 0, hi = 1e9;
        int ans;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cur = 0;
            int tmp = 0;
            for (auto e : diff) {
                if (e <= mid) cur++;
                else {
                    tmp += (cur + 1) / 2;
                    cur = 0;
                }
            }
            tmp += (cur + 1) / 2;
            if (tmp >= p) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};