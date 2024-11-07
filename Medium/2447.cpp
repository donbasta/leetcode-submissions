class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) ans++;
            int cur = nums[i];
            for (int j = i + 1; j < n; j++) {
                cur = __gcd(cur, nums[j]);
                if (cur == k) ans++;
            }
        }
        return ans;
    }
};