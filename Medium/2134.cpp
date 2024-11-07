class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c = count(nums.begin(), nums.end(), 1);
        int tmp = 0;
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < c; i++) {
            tmp += nums[i] == 1;
        }
        int p = c;
        for (int i = 0; i < n; i++) {
            ans = min(ans, c - tmp);
            tmp -= nums[i] == 1;
            if (p >= n) p -= n;
            tmp += nums[p++] == 1;
        }
        return ans;
    }
};