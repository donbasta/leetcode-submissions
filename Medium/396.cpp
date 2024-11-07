class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int tmp = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            tmp += i * nums[i];
            sum += nums[i];
        }
        int ans = tmp;
        for (int i = n - 1; i >= 1; i--) {
            tmp += (sum - (n) * nums[i]);
            ans = max(ans, tmp);
        }
        return ans;
    }
};