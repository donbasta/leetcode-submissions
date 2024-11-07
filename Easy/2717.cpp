class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int p1 = -1, pn = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) p1 = i;
            if (nums[i] == n) pn = i;
        }
        return (p1 - 1) + (n - pn) - (p1 > pn);
    }
};