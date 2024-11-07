class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> ve(n + 1);
        if (n == 0) return 0;
        ve[1] = 1;
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (i & 1) ve[i] = ve[i / 2] + ve[i / 2 + 1];
            else ve[i] = ve[i / 2];
            ans = max(ans, ve[i]);
        }
        return ans;
    }
};