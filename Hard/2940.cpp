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
    int get(int l, int r) {
        int i = bit_width(r - l + 1) - 1;
        return max(table[i][l], table[i][r - (1 << i) + 1]);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SparseTable st(heights);
        vector<int> ret;
        int n = heights.size();
        for (auto q : queries) {
            int a = q[0], b = q[1];
            if (a == b) {
                ret.push_back(a);
                continue;
            }
            if (a > b) swap(a, b);
            if (heights[b] > heights[a]) {
                ret.push_back(b);
                continue;
            }
            int start = b + 1;
            int le = start, ri = n - 1, piv = -1;
            int need = max(heights[a], heights[b]) + 1;
            while (le <= ri) {
                int mid = (le + ri) >> 1;
                if (st.get(start, mid) >= need) {
                    piv = mid;
                    ri = mid - 1;
                } else {
                    le = mid + 1;
                }
            }
            ret.push_back(piv);
        }
        return ret;
    }
};