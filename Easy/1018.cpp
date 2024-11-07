class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur = 0;
        vector<bool> ret;
        for (auto c : nums) {
            cur = (cur * 2 + c) % 5;
            ret.push_back(cur == 0);
        }
        return ret;
    }
};