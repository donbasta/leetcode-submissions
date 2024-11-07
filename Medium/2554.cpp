class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        const int M = 1e4;
        vector<bool> isBanned(M + 1);
        for (auto e : banned) {
            isBanned[e] = true;
        }
        int ans = 0;
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (isBanned[i]) continue;
            if (tmp + i > maxSum) {
                return ans;
            }
            ans++;
            tmp += i;
        }
        return ans;
    }
};