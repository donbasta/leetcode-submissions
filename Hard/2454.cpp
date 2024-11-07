struct Segtree {
    int n;
    vector<int> tree;
    Segtree(const vector<int>& ar) {
        n = ar.size();
        tree.resize(4 * n + 5);
        build(1, 0, n - 1, ar);
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    int get(int l, int r) {
        if (l > r) return -1;
        return get(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        Segtree sgt(nums);
        vector<int> R(n, n);
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            while (!ve.empty() && ve.back().first < nums[i]) {
                R[ve.back().second] = i;
                ve.pop_back();
            }
            ve.emplace_back(nums[i], i);
        }

        for (int i = 0; i < n; i++) {
            int nx = R[i];
            if (nx == n) continue;
            int l = nx + 1, r = n - 1, piv = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sgt.get(nx + 1, mid) > nums[i]) {
                    piv = mid;
                    r = piv - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (piv != -1) ans[i] = piv;
        }
        for (auto& e : ans) if (e != -1) e = nums[e];
        return ans;
    }
};