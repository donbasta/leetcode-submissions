class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int m = groups.size();
        while (i < n) {
            int cur_sz = groups[j].size();
            if (i + cur_sz > n) break;
            if (groups[j] == vector<int>(nums.begin() + i, nums.begin() + i + cur_sz)) {
                j++;
                i += cur_sz;
            } else {
                i++;
            }
            if (j >= m) break;
        }
        return j >= m;
    }
};