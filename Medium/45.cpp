struct BIT {

};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        const int INF = 2e9;
        for (int i = 1; i < n; i++) {
            int tmp = INF;
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) tmp = min(tmp, dp[j] + 1);
            }
            dp[i] = tmp;
        }
        return dp[n - 1];
    }
};