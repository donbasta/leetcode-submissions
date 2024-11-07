class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        long long val = 0;
        vector<long long> pw10(15);
        pw10[0] = 1;
        for (int i = 1; i < 15; i++) {
            pw10[i] = pw10[i - 1] * 10;
        }
        while (l <= r) {
            if (l == r) val += nums[l];
            else {
                val += nums[r];
                int digr = floor(log10(nums[r])) + 1;
                val += (nums[l] * pw10[digr]);
            }
            l++, r--;
        }
        return val;
    }
};