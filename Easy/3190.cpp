class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ret = 0;
        for (auto e : nums) {
            ret += (e % 3 != 0);
        }
        return ret;
    }
};