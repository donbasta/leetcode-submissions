class Solution {
public:
    int minOperations(int n) {
        vector<int> dp(n + 1);
        const int INF = 2e9;
        for (int i = 1; i <= n; i++) {
            int tmp = INF;
            for (int j = 0; j < 32; j++) {
                if ((1 << j) > i) break;
                tmp = min(tmp, 1 + dp[i - (1 << j)]);
            }
            int tot = 0;
            int ni = i;
            vector<int> ve;
            while (ni) {
                ve.emplace_back(ni & 1);
                ni >>= 1;
            }
            int k;
            for (int j = 0; j < ve.size(); j = k) {
                if (ve[j] == 1) {
                    tot++;
                    k = j;
                    while (k < ve.size() && ve[k] == 1) {
                        k++;
                    }
                    if (k < ve.size()) ve[k] = 1;
                } else {
                    k = j + 1;
                }
            }
            tmp = min(tmp, tot + 1);
            dp[i] = tmp;
        }
        return dp[n];
    }
};