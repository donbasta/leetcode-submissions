class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) return ret;
        int start = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if ((long long)nums[i] - nums[i - 1] == 1) {
                continue;
            } else {
                if (nums[i - 1] == start) {
                    ret.push_back(to_string(start));
                } else {
                    string tmp = to_string(start) + "->" + to_string(nums[i - 1]);
                    ret.push_back(tmp);
                }
                start = nums[i];
            }
        }
        if (nums.back() == start) {
            ret.push_back(to_string(start));
        } else {
            string tmp = to_string(start) + "->" + to_string(nums.back());
            ret.push_back(tmp);
        }
        return ret;
    }
};