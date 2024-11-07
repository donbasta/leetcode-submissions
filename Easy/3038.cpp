class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 1, tot = nums[0] + nums[1];
        for (int i = 2; i + 1 < n; i += 2) {
            if (nums[i] + nums[i + 1] != tot) break;
            op++;
        }
        return op;
    }
};