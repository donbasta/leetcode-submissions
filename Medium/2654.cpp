class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int sh = -1;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int tmp = 0;
                for (int j = i; j <= i + len - 1; j++) {
                    tmp = __gcd(tmp, nums[j]);
                }
                if (tmp == 1) {
                    sh = len;
                    break;
                }
            }
            if (sh != -1) break;
        }
        if (sh == -1) return -1;
        if (sh == 1) {
            int c1 = count(nums.begin(), nums.end(), 1);
            return n - c1;
        }
        return n - 2 + sh;
    }
};