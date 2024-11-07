class SparseTable {
private:
    vector<vector<int>> table;
    int n;
public:
    SparseTable(const vector<int>& ar) : n(ar.size()) {
        table.resize(20);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[i][j] = (table[i - 1][j] & table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int bit_width(int x) {
        if (x == 0) return 0;
        int ret = 0;
        while (x) {x >>= 1, ret++;}
        return ret;
    }
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return (table[i][l] & table[i][r - (1 << i) + 1]);
    }
};

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        SparseTable st(arr);
        int n = arr.size();
        int ret = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            int ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (st.get(i, mid) > target) {
                    l = mid + 1;
                } else {
                    ans = mid;
                    r = mid - 1;
                }
            }
            if (ans == -1) {
                ret = min(ret, st.get(i, n - 1) - target);
            } else {
                ret = min(ret, target - st.get(i, ans));
                if (ans > i) ret = min(ret, st.get(i, ans - 1) - target);
            }
        }
        return ret;
    }
};