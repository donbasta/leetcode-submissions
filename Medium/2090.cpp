class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n, -1);
        long long sum = 0;
        for (int i = 0; i <= min(n - 1, 2 * k); i++) {
            sum += nums[i];
        }
        for (int i = k; i < n - k; i++) {
            ret[i] = sum / (k * 2 + 1);
            sum -= nums[i - k];
            if (i < n - k - 1) sum += nums[i + k + 1];
        }
        return ret;
    }
};