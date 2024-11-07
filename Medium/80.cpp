class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int last = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[last] && cnt >= 2) continue;
            if (nums[i] == nums[last]) cnt++;
            else cnt = 1;
            nums[++last] = nums[i];
        }
        return last + 1;
    }
};