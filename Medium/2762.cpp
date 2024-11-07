struct Segtree {
    vector<pair<int, int>> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& arr) {
        if (s == e) {
            tree[v] = make_pair(arr[s], arr[s]);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, arr);
        build(v << 1 | 1, mid + 1, e, arr);
        tree[v] = make_pair(max(tree[v << 1].first, tree[v << 1 | 1].first), min(tree[v << 1].second, tree[v << 1 | 1].second));
    }
    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        else {
            pair<int, int> X = get(v << 1, s, mid, l, mid);
            pair<int, int> Y = get(v << 1 | 1, mid + 1, e, mid + 1, r);
            return make_pair(max(X.first, Y.first), min(X.second, Y.second));
        }
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        Segtree seg(n);
        seg.build(1, 0, n - 1, nums);
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            int ans = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                pair<int, int> check = seg.get(1, 0, n - 1, i, mid);
                if (check.first - check.second <= 2) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ret += (ans - i + 1);
        }
        return ret;
    }
};