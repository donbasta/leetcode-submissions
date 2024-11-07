class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        vector<pair<int, int>> tmp;
        int n = arr.size();
        int le[n], ri[n];
        memset(le, -1, sizeof(le));
        for (int i = 0; i < n; i++) ri[i] = n;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && arr[i] < tmp.back().second) {
                ri[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, arr[i]);
        }
        tmp.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && arr[i] <= tmp.back().second) {
                le[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int L = le[i] + 1, R = ri[i] - 1;
            ans = (1ll * ans + 1ll * arr[i] * (R - i + 1) * (i - L + 1)) % MOD;
        }
        return ans;
    }
};