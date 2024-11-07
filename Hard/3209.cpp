struct SparseTable {
    const int K = 20;
    vector<vector<int>> table;
    int n;
    SparseTable(const vector<int>& ar) : n(ar.size()) {
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = (table[i - 1][j] & table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {
            x >>= 1, ret++;
        }
        return ret;
    }
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return (table[i][l] & table[i][r - (1 << i) + 1]);
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        SparseTable st(nums);
        int n = nums.size();
        using ll = long long;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            int pr = -1, pl = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (st.get(i, mid) > k) {
                    l = mid + 1;
                } else {
                    pl = mid;
                    r = mid - 1;
                }
            }
            l = i, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (st.get(i, mid) >= k) {
                    l = mid + 1;
                } else {
                    pr = mid;
                    r = mid - 1;
                }
            }
            ll add = 0;
            if (pr == -1 && pl == -1) {
                add = 0;
            } else if (pl == -1) {
                add = 0;
            } else if (pr == -1) {
                add = n - pl;
            } else {
                add = pr - pl;
            }
            ans += add;
        }
        return ans;
    }
};