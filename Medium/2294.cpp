class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int sz = nums.size();
        int part = 0;
        while (start < sz) {
            int nx = upper_bound(nums.begin(), nums.end(), nums[start] + k) - nums.begin();
            --nx;
            part++;
            start = nx + 1;
        }
        return part;
    }
};