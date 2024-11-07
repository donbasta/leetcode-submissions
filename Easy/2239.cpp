class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mn = INT_MAX, ret = -1;
        for (auto c : nums) {
            if (abs(c) < mn) {
                ret = c, mn = abs(c);
            } else if (abs(c) == mn && c > ret) {
                ret = c;
            }
        }
        return ret;
    }
};