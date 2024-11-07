class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int cur = 0;
        set<int> se;
        se.insert(0);
        for (int i = 1; i < nums.size(); i++) {
            int lmao = cur + nums[i - 1] + nums[i];
            if (se.count(lmao % k)) {
                return true;
            }
            cur += nums[i - 1];
            se.insert(cur % k);
        }
        return false;
    }
};