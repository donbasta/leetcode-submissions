class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int p = maxHeights[i];
            long long tmp = p;
            for (int j = i - 1; j >= 0; j--) {
                tmp += 1ll * min(p, maxHeights[j]);
                p = min(p, maxHeights[j]);
            }
            p = maxHeights[i];
            for (int j = i + 1; j < n; j++) {
                tmp += 1ll * min(p, maxHeights[j]);
                p = min(p, maxHeights[j]);
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};