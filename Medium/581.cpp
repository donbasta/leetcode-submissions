class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> lmao = nums;
        sort(lmao.begin(), lmao.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < n && nums[l] == lmao[l]) l++;
        while (r >= 0 && nums[r] == lmao[r]) r--;
        if (l == n) return 0;
        return r - l + 1;
    }
};