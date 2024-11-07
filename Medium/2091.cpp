class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a = max_element(nums.begin(), nums.end()) - nums.begin();
        int b = min_element(nums.begin(), nums.end()) - nums.begin();
        if (a > b) swap(a, b);
        int n = nums.size();
        int ret = (a + 1 + n - b);
        ret = min(ret, b + 1);
        ret = min(ret, n - a);
        return ret;
    }
};