class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n / 2;
        int ans = 1;
        vector<int> R(n);
        R[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) R[i] = R[i + 1];
            else R[i] = i;
        }

        auto ok = [&](int k) -> bool {
            for (int i = 0; i + 2 * k - 1 < n; i++) {
                bool ok = true;
                if (R[i] < i + k - 1) ok = false;
                if (R[i + k] < i + 2 * k - 1) ok = false;
                if (ok) return true;
            }
            return false;
        };

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};