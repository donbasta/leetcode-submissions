class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!ret.empty() && (ret.back() > nums[i]) && (ret.size() + n - 1 - i >= k)) {
                ret.pop_back();
            }
            ret.push_back(nums[i]);
        }
        while (ret.size() > k) ret.pop_back();
        return ret;
    }
};