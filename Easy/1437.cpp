class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (last == -1) {
                    last = i;
                } else {
                    if (i - last <= k) return false;
                    last = i;
                }
            }
        }
        return true;
    }
};