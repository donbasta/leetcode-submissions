class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int x = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            x &= (nums[i]);
        }
        if (x > 0) {
            return 1;
        }
        int cur = nums[0];
        int par = 0;
        for (int i = 1; i < n; i++) {
            if (cur == x) {
                par++;
                cur = nums[i];
            } else {
                cur &= (nums[i]);
            }
        }
        if (cur == x) {
            par++;
        }
        return par;
    }
};