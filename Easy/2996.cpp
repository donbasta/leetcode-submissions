class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int i = 1;
        while (i < n) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
                i++;
            } else {
                break;
            }
        }
        while (true) {
            bool ada = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == sum) {
                    ada = true;
                    break;
                }
            }
            if (ada) {
                sum++;
            } else {
                return sum;
            }
        }
        return -1;
    }
};