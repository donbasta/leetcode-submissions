class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long ans = 0;
        const long long A = 5e8;
        for (int i = 0; i < k; i++) {
            long long lmao = 0;
            long long l = 0, r = A;
            while (l <= r) {
                long long mid = (l + r) >> 1; //try to create mid alloy
                vector<long long> tmp(n);
                long long need = 0;
                for (int j = 0; j < n; j++) {
                    tmp[j] = 1ll * composition[i][j] * mid;
                    if (stock[j] >= tmp[j]) continue;
                    need += 1ll * (tmp[j] - stock[j]) * cost[j];
                }
                if (need <= (1ll * budget)) {
                    lmao = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, lmao);
        }
        return int(ans);
    }
};


