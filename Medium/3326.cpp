bool precompute = false;
const int M = 1e6;
int lpf[M + 1];
bool pr[M + 1];

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        const int INF = 2e9;
        for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) dp[i][j] = INF;

        if (!precompute) {
            memset(lpf, -1, sizeof(lpf));
            memset(pr, true, sizeof(pr));
            pr[1] = false;
            lpf[1] = 1;
            for (int i = 2; i <= M; i++) {
                if (!pr[i]) continue;
                lpf[i] = i;
                for (int j = i + i; j <= M; j += i) {
                    pr[j] = false;
                    if (lpf[j] == -1) lpf[j] = i;
                }
            }
            precompute = true;
        }

        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            if (nums[i] >= lpf[nums[i - 1]]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            if (lpf[nums[i]] >= nums[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
            if (lpf[nums[i]] >= lpf[nums[i - 1]]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
        }

        int ans = min(dp[n - 1][0], dp[n - 1][1]);
        if (ans == INF) ans = -1;
        return ans;
    }
};