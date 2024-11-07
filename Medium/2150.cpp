class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            if (i > 0) ok &= (nums[i - 1] < nums[i] - 1);
            if (i < n - 1) ok &= (nums[i + 1] > nums[i] + 1);
            if (ok) ret.push_back(nums[i]);
        }
        return ret;
    }
};