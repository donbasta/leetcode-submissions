class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        const int INF = 1e9;

        const function<int(vector<int>)> LIS = [&](vector<int> A) -> int {
            int sz = A.size();
            vector<int> dp(sz + 1, INF);
            dp[0] = -INF;
            for (int i = 0; i < sz; i++) {
                int u = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
                if (dp[u - 1] <= A[i] && A[i] < dp[u]) dp[u] = A[i];
            }
            for (int i = sz; i >= 0; i--) {
                if (dp[i] < INF) return i;
            }
            return -1;
        };

        int ans = 0;
        for (int i = 0; i < k; i++) {
            vector<int> tmp;
            for (int j = i; j < n; j += k) {
                tmp.push_back(arr[j]);
            }
            int lis = LIS(tmp);
            ans += tmp.size() - lis;
        }
        return ans;
    }
};