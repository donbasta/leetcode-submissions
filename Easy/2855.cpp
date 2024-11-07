class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int st = min_element(nums.begin(), nums.end()) - nums.begin();
        int a = st;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int nx = (st + 1) % n;
            if (nums[nx] <= nums[st]) return -1;
            st = (st + 1) % n;
        }
        if (a == 0) return 0;
        return n - a;
    }
};