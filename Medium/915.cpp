class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> mn(n), mx(n);
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], nums[i]);
        mn[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) mn[i] = min(mn[i + 1], nums[i]);
        for (int i = 0; i < n - 1; i++) {
            if (mx[i] <= mn[i + 1]) {
                return i + 1;
            }
        }
        assert(false);
        return -1;
    }
};