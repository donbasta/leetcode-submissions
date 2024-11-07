class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;

        auto is_prime = [&](int x) -> bool {
            if (x == 1) return false;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (is_prime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }
            if (is_prime(nums[i][n - 1 - i])) {
                ans = max(ans, nums[i][n - 1 - i]);
            }
        }
        return ans;
    }
};