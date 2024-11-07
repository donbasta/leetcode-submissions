struct BIT {
    int _n;
    vector<int> tree;
    BIT(int n) : _n(n) {
        tree.resize(n + 1);
    }
    void add(int idx, int val) {
        while (idx <= _n) {
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
    int get(int a, int b) {
        return get(b) - get(a - 1);
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        BIT bit(n + 5);
        bit.add(1, 1);
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '1') continue;
            int mn = max(1, i - maxJump);
            int mx = i - minJump;
            if (mx <= 0) continue;
            int cek = bit.get(mn, mx);
            if (cek > 0) {
                bit.add(i, 1);
            }
        }
        int lmao = bit.get(n, n);
        return (lmao > 0);
    }
};