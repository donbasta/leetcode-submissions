struct Segtree2D {
    int n;
    vector<vector<int>> tree;
    Segtree2D(vector<vector<int>>& ve) : n(ve.size()) {
        tree.assign(2 * n + 1, vector<int>(2 * n + 1));
        for (int i = 2 * n - 1; i >= n; i--) {
            for (int j = 2 * n - 1; j >= n; j--) { tree[i][j] = ve[i - n][j - n]; }
            for (int j = n - 1; j >= 0; j--) {
                tree[i][j] = max(tree[i][j << 1], tree[i][j << 1 | 1]);
            }
        }
        for (int i = n - 1; i > 0; i--) {
            for (int j = 2 * n - 1; j >= 0; j--) { tree[i][j] = max(tree[i << 1][j], tree[i << 1 | 1][j]); }
            for (int j = n - 1; j >= 0; j--) {
                tree[i][j] = max(tree[i][j << 1], tree[i][j << 1 | 1]);
            }
        }
    }
    int get(int lx, int rx, int ly, int ry) {
        int ret = 0;
        for (lx += n, rx += n; lx < rx; lx >>= 1, rx >>= 1) {
            if (lx & 1) {
                int ll = ly, rr = ry;
                for (ll += n, rr += n; ll < rr; ll >>= 1, rr >>= 1) {
                    if (ll & 1) ret = max(ret, tree[lx][ll++]);
                    if (rr & 1) ret = max(ret, tree[lx][--rr]);
                }
                lx++;
            }
            if (rx & 1) {
                --rx;
                int ll = ly, rr = ry;
                for (ll += n, rr += n; ll < rr; ll >>= 1, rr >>= 1) {
                    if (ll & 1) ret = max(ret, tree[rx][ll++]);
                    if (rr & 1) ret = max(ret, tree[rx][--rr]);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> val(n, vector<int>(n));
        for (int i = 0; i < n; i++) val[i][i] = nums[i];
        for (int i = 0; i < n - 1; i++) val[i][i + 1] = (nums[i] ^ nums[i + 1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                val[i][i + len - 1] = (val[i][i + len - 2] ^ val[i + 1][i + len - 1]);
            }
        }
        Segtree2D sgt(val);
        vector<int> ret;
        for (auto q : queries) {
            int L = q[0], R = q[1];
            ret.push_back(sgt.get(L, R + 1, L, R + 1));
            //max of val[L][L], ... val[R][R]
        }
        return ret;
    }
};