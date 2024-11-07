class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i += 2) {
            ret.push_back(nums[i + 1]);
            ret.push_back(nums[i]);
        }
        return ret;
    }
};