class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        vector<bool> l(n), r(n);
        l[0] = true;
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] && (nums[i] > nums[i - 1]);
        }
        r[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] && (nums[i] < nums[i + 1]);
        }
        if (l[n - 1]) return true;
        if (r[1]) return true;
        if (l[n - 2]) return true;
        for (int i = 1; i < n - 1; i++) {
            if (l[i - 1] && r[i + 1] && (nums[i - 1] < nums[i + 1])) return true;
        }
        return false;
    }
};