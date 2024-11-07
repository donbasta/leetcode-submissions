class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -2e9;
        for (int i = 0; i <= 3; i++) {
            int tmp = 1;
            for (int j = 0; j < i; j++) tmp *= nums[j];
            for (int j = 0; j < 3 - i; j++) tmp *= nums[n - 1 - j];
            ans = max(ans, tmp);
        }
        return ans;
    }
};