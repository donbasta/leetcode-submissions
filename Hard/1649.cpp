struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n) {tree.resize(n + 1);}
    void upd(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    int get(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
    int get(int l, int r) {
        if (r < l) return 0;
        return get(r) - get(l - 1);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        set<int> se;
        for (auto e : instructions) se.insert(e);
        int cnt = 0;
        unordered_map<int, int> cmp;
        for (auto e : se) cmp[e] = ++cnt;

        BIT bit(cnt);
        int ans = 0;
        const int mod = 1e9 + 7;
        for (auto e : instructions) {
            int kiri = bit.get(1, cmp[e] - 1);
            int kanan = bit.get(cmp[e] + 1, cnt);
            ans = (ans + min(kiri, kanan)) % mod;
            bit.upd(cmp[e], 1);
        }
        return ans;
    }
};