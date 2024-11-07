class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret, emp;
        int n = nums.size();
        if (n % 3 != 0) {
            return emp;
        }
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return emp;
            }
            vector<int> tmp;
            tmp.push_back(nums[i]);
            tmp.push_back(nums[i + 1]);
            tmp.push_back(nums[i + 2]);
            ret.push_back(tmp);
        }
        return ret;
    }
};