class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        int pre[n], suf[n];
        pre[0] = arr[0];
        int sum = arr[0];
        int mn = min(0, arr[0]);
        for (int i = 1; i < n; i++) {
            sum += arr[i];
            pre[i] = sum - mn;
            mn = min(mn, sum);
        }
        suf[n - 1] = arr[n - 1];
        sum = arr[n - 1];
        mn = min(0, arr[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            sum += arr[i];
            suf[i] = sum - mn;
            mn = min(mn, sum);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans = max(ans, max(suf[0], suf[1]));
            } else if (i == n - 1) {
                ans = max(ans, max(pre[n - 1], pre[n - 2]));
            } else {
                ans = max(ans, pre[i - 1] + suf[i + 1] + max(0, arr[i]));
            }
        }
        return ans;
    }
};