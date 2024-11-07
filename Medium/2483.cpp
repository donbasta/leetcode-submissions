class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int pre[n + 1];
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (customers[i] == 'N');
        }
        int ans = -1;
        int mn = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int penalty = pre[i] + (n - pre[n] - (i - pre[i]));
            if (penalty < mn) {
                ans = i;
                mn = penalty;
            }
        }
        return ans;
    }
};