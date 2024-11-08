class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }
        return ans;
    }
};