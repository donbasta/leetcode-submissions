class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> S1[n + 2][k + 1], S2[n + 2][k + 1];
        for (int i = 0; i <= n + 1; i++) S1[i][0].push_back(0);
        for (int i = 0; i <= n + 1; i++) S2[i][0].push_back(0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (auto c : S1[i - 1][j]) {
                    S1[i][j].emplace_back(c);
                }
                for (auto c : S1[i - 1][j - 1]) {
                    S1[i][j].emplace_back(c | nums[i - 1]);
                }
                sort(S1[i][j].begin(), S1[i][j].end());
                S1[i][j].resize(unique(S1[i][j].begin(), S1[i][j].end()) - S1[i][j].begin());
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= k; j++) {
                for (auto c : S2[i + 1][j]) {
                    S2[i][j].emplace_back(c);
                }
                for (auto c : S2[i + 1][j - 1]) {
                    S2[i][j].emplace_back(c | nums[i - 1]);
                }
                sort(S2[i][j].begin(), S2[i][j].end());
                S2[i][j].resize(unique(S2[i][j].begin(), S2[i][j].end()) - S2[i][j].begin());
            }
        }
        int ans = 0;
        for (int i = k; i <= n - k; i++) {
            for (auto x : S1[i][k]) {
                for (auto y : S2[i + 1][k]) {
                    ans = max(ans, x ^ y);
                }
            }
        }
        return ans;
    }
};