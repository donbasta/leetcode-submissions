class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mn = INT_MAX;
        int lmao = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cur = nums[i] + nums[j];
                int need = target - cur;
                int hehe = upper_bound(nums.begin() + j + 1, nums.end(), need) - nums.begin();
                if (hehe < n) {
                    int tot = cur + nums[hehe];
                    if (abs(tot - target) < mn) {
                        mn = abs(tot - target);
                        lmao = tot;
                    } 
                }
                if (hehe - 1 > j) {
                    int tot = cur + nums[hehe - 1];
                    if (abs(tot - target) < mn) {
                        mn = abs(tot - target);
                        lmao = tot;
                    } 
                }
            }
        }
        return lmao;
    }
};