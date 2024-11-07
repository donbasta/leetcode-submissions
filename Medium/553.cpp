class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ret = to_string(nums[0]);
        ret += "/(";
        for (int i = 1; i < n; i++) {
            ret += to_string(nums[i]);
            if (i < n - 1) ret += '/';
        }
        ret += ")";
        return ret;
    }
};