class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<int> le(n, -1), ri(n, n);
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && tmp.back().first >= maxHeights[i]) {
                ri[tmp.back().second] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(maxHeights[i], i);
        }
        tmp.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && tmp.back().first >= maxHeights[i]) {
                le[tmp.back().second] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(maxHeights[i], i);
        }
        vector<long long> pr(n), su(n);
        pr[0] = maxHeights[0];
        for (int i = 1; i < n; i++) {
            int j = le[i];
            pr[i] = (j >= 0 ? pr[j] : 0) + 1ll * (maxHeights[i]) * (i - j);
        }
        su[n - 1] = maxHeights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int j = ri[i];
            su[i] = (j < n ? su[j] : 0) + 1ll * (maxHeights[i]) * (j - i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pr[i] + su[i] - maxHeights[i]);
        }
        return ans;
    }
};