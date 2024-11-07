class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) continue;
            int cur = i;
            int last;
            while (nums[cur] != -1) {
                last = nums[cur];
                nums[cur] = -1;
                cur = (last - 1);
            }
            if (cur != i) return last;

        }
        return -1;
    }
};