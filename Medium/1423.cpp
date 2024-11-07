class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = cardPoints[i] + (i ? pref[i - 1] : 0);
        }
        if (k == n) return pref[n - 1];
        int ans = pref[n - 1] - pref[n - k - 1];
        for (int i = 0; i < k; i++) {
            ans = max(ans, pref[i] + pref[n - 1] - pref[n - k + i]);
        }
        return ans;
    }
};