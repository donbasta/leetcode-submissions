class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int ret = INT_MAX;
        while (i < j) {
            ret = min(ret, nums[i] + nums[j]);
            i++, j--;
        }
        return (double)ret / 2;
    }
};