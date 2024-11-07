class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        int mx = nums[idx];
        sort(nums.begin(), nums.end());
        if (mx >= 2 * nums[nums.size() - 2]) return idx;
        return -1;
    }
};