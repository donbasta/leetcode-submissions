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
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        sort(rooms.begin(), rooms.end());
        vector<int> sz(n), id(n);
        for (int i = 0; i < n; i++) sz[i] = rooms[i][1];
        for (int i = 0; i < n; i++) id[i] = rooms[i][0];
        SparseTable st(sz);
        vector<int> ret;
        for (auto q : queries) {
            int x = q[0];
            int need = q[1];
            int j = upper_bound(id.begin(), id.end(), x) - id.begin();
            //0..j-1 ke kiri, dan j..n-1 ke kanan
            int ans = INT_MAX;
            int room = -1;
            {
                int l = 0, r = j - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (st.get(mid, j - 1) >= need) {
                        pos = mid, l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (pos != -1) {
                    if (abs(x - id[pos]) < ans) {
                        ans = abs(x - id[pos]);
                        room = id[pos];
                    }
                }
            }
            {
                int l = j, r = n - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (st.get(j, mid) >= need) {
                        pos = mid, r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                if (pos != -1) {
                    if (abs(x - id[pos]) < ans) {
                        ans = abs(x - id[pos]);
                        room = id[pos];
                    }
                }
            }
            if (ans == INT_MAX) ret.push_back(-1);
            else ret.push_back(room);
        }
        return ret;
    }
};