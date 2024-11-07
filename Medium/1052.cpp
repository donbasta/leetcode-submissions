class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int tot = 0;
        int n = grumpy.size();
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) tot += customers[i];
            pre[i] = (i ? pre[i - 1] : 0);
            if (grumpy[i] == 1) pre[i] += customers[i]; 
        }
        int ans = tot;
        for (int i = 0; i <= n - minutes; i++) {
            ans = max(ans, tot + pre[i + minutes - 1] - (i ? pre[i - 1] : 0));
        }
        return ans;
    }
};