class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        auto isPrime = [&](int x) -> bool {
            if (x == 1) return false;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };
        int n = nums.size();
        int mn = n, mx = -1;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                mn = min(mn, i), mx = max(mx, i);
            }
        }
        return mx - mn;
    }
};