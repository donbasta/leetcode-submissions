class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> diffs;
        for (int i = 1; i < nums.size(); i++) {
            diffs.emplace_back(nums[i] - nums[i - 1]);
        }
        const int INF = 2e9;
        int cur = INF;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] == cur) {
                cnt++;
            } else {
                ans += (cnt * (cnt - 1) / 2);
                cur = diffs[i];
                cnt = 1;
            }
        }
        ans += (cnt * (cnt - 1) / 2);
        return ans;
    }
};