class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> hehe(2, -1);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (hehe[0] == -1) hehe[0] = i;
                hehe[1] = i;
            }
        }
        return hehe;
    }
};