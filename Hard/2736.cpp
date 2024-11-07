struct MergesortTree {
    vector<vector<pair<int, int>>> tree;
    vector<vector<int>> pref;
    MergesortTree(int n) {
        tree.resize(4 * n + 5);
        pref.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<pair<int, int>>& ar) {
        if (s == e) {
            tree[v] = {make_pair(ar[s].second, ar[s].second + ar[s].first)};
            pref[v] = {ar[s].second + ar[s].first};
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        merge(tree[v << 1].begin(), tree[v << 1].end(), tree[v << 1 | 1].begin(), tree[v << 1 | 1].end(), back_inserter(tree[v]));
        int sz = tree[v].size();
        pref[v].resize(sz);
        pref[v].back() = tree[v].back().second;
        for (int i = sz - 2; i >= 0; i--) {
            pref[v][i] = max(pref[v][i + 1], tree[v][i].second);
        }
    }
    int query(int v, int s, int e, int l, int r, int y) {
        if (s == l && e == r) {
            int x = lower_bound(tree[v].begin(), tree[v].end(), make_pair(y, 0)) - tree[v].begin();
            if (x == (int)pref[v].size()) {
                return -1;
            } else {
                return pref[v][x];
            }
        }
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return query(v << 1, s, mid, l, r, y);
        } else if (l >= mid + 1) {
            return query(v << 1 | 1, mid + 1, e, l, r, y);
        }
        return max(query(v << 1, s, mid, l, mid, y), query(v << 1 | 1, mid + 1, e, mid + 1, r, y));
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<pair<int, int>> lol;
        for (int i = 0; i < n; i++) {
            lol.emplace_back(nums1[i], nums2[i]);
        }
        sort(lol.begin(), lol.end());
        MergesortTree sgt(n);
        sgt.build(1, 0, n - 1, lol);
        vector<int> ret;
        for (auto q : queries) {
            int x = q[0], y = q[1];
            int idx = lower_bound(lol.begin(), lol.end(), make_pair(x, 0)) - lol.begin();
            if (idx == n) {
                ret.push_back(-1);
            } else {
                ret.push_back(sgt.query(1, 0, n - 1, idx, n - 1, y));
            }
        }
        return ret;
    }
};