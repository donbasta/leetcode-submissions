class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += nums[i];
        }
        int mx_sum = INT_MIN;
        for (int i = k - 1; i < n; i++) {
            sum += nums[i];
            mx_sum = max(mx_sum, sum);
            sum -= nums[i - k + 1];
        }
        return (double) mx_sum / (double) k;
    }
};