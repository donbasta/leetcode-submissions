class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> to(n);
        vector<int> in(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (nums[i] % nums[j] == 0) {
                    to[j].push_back(i);
                    in[i]++;
                }
            }
        }

        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) Q.push(i);
        }
        
        vector<int> dp(n, 1);
        vector<int> prv(n, -1);
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto e : to[cur]) {
                in[e]--;
                if (dp[cur] + 1 > dp[e]) {
                    prv[e] = cur, dp[e] = dp[cur] + 1;
                }
                if (in[e] == 0) {
                    Q.push(e);
                }
            }
        }

        int mx = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > mx) {
                mx = dp[i], last = i;
            }
        }

        vector<int> ans = {nums[last]};
        while (prv[last] != -1) {
            ans.push_back(nums[prv[last]]);
            last = prv[last];
        }
        return ans;
    }
};