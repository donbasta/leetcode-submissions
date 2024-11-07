class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        using ll = long long;
        int q = queries.size();
        bool r[n], c[n];
        for (int i = 0; i < n; i++) r[i] = c[i] = false;
        int rem_row = n, rem_col = n;
        ll ans = 0;
        for (int i = q - 1; i >= 0; i--) {
            int type = queries[i][0];
            int idx = queries[i][1];
            int val = queries[i][2];
            if (type == 1) {
                if (r[idx]) continue;
                ans += 1ll * val * rem_col;
                r[idx] = true;
                rem_row--;
            } else {
                if (c[idx]) continue;
                ans += 1ll * val * rem_row;
                c[idx] = true;
                rem_col--;
            }
        }
        return ans;
    }
};