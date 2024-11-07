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
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        SparseTable st(nums);
        for (int i = 0; i < n; i++) {
            int lo = i, hi = n - 1, piv = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (st.get(i, mid) > k) {
                    lo = mid + 1;
                } else {
                    piv = mid;
                    hi = mid - 1;
                }
            }
            // piv : pertama <= k, piv - 1 > k
            if (piv == -1) {
                ans = min(ans, st.get(i, n - 1) - k);
            } else {
                ans = min(ans, k - st.get(i, piv));
                if (piv > i) {
                    ans = min(ans, st.get(i, piv - 1) - k);
                }
            }
        }
        return ans;
    }
};