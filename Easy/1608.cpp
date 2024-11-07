class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int prv = (i == 0 ? -1 : nums[i - 1]);
            //(prv + 1)..(nums[i]) ada yang nilainya n - i ga
            if ((n - i) >= (prv + 1) && (n - i) <= nums[i]) {
                return (n - i);
            }
        }
        return -1;
    }
};