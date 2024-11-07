class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        sort(nums.begin(), nums.end());

        int mn = (n + 1) / 2;
        int idx = mn - 1;
        for (int i = 0; i < n; i += 2) {
            ret[i] = nums[idx--];
        }
        idx = n - 1;
        for (int i = 1; i < n; i += 2) {
            ret[i] = nums[idx--];
        }
        nums = ret;
    }
};