class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n), mn(n);
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], nums[i]);
        mn[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) mn[i] = min(mn[i + 1], nums[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((nums[i] > mx[i - 1]) && (nums[i] < mn[i + 1])) ans += 2;
            else if ((nums[i] > nums[i - 1]) && (nums[i] < nums[i + 1])) ans++;
        }
        return ans;
    }
};