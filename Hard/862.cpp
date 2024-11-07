class SparseTable {
public:
    const int K = 20;
    vector<vector<long long>> table;
    int n;
    SparseTable(const vector<long long>& ar) : n(ar.size()) {
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
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
    long long get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return max(table[i][l], table[i][r - (1 << i) + 1]);
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        SparseTable st(pre);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            int idx = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (st.get(l + 1, mid + 1) >= pre[i] + k) {
                    idx = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (idx == -1) continue;
            else {
                ans = min(ans, idx - i + 1);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};