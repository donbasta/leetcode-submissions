class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = b + 1; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {
                        ans += (nums[a] + nums[b] + nums[c] == nums[d]);
                    }
                }
            }
        }
        return ans;
    }
};