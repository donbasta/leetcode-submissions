class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        const int INF = 2e9;
        vector<int> dp(n, INF);
        for (int i = 0; i < n; i++) {
            int cur = books[i][0];
            int mx = books[i][1];
            dp[i] = min(dp[i], mx + (i ? dp[i - 1] : 0));
            int j = i - 1;
            while (j >= 0 && cur + books[j][0] <= shelfWidth) {
                cur += books[j][0];
                mx = max(mx, books[j][1]);
                dp[i] = min(dp[i], mx + (j ? dp[j - 1] : 0));
                j--;
            }
        }
        return dp[n - 1];
    }
};