struct Segtree {
    vector<int> tree;
    Segtree(int n) {tree.resize(4 * n + 5);}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {tree[v] = max(tree[v], val); return;}
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> heights;
        for (auto e : envelopes) {
            heights.push_back(e[1]);
        }
        sort(heights.begin(), heights.end());
        heights.resize(unique(heights.begin(), heights.end()) - heights.begin());
        unordered_map<int, int> ump;
        int cnt = 0;
        for (auto h : heights) ump[h] = cnt++;
        Segtree sgt(cnt);

        int curWidth = 0;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (envelopes[i][0] > curWidth) {
                if (curWidth != 0) {
                    unordered_map<int, int> buff;
                    for (auto e : tmp) {
                        int idx = lower_bound(heights.begin(), heights.end(), e) - heights.begin();
                        buff[e] = 1;
                        if (idx) buff[e] = sgt.get(1, 0, cnt - 1, 0, idx - 1) + 1;
                    } 
                    for (auto e : buff) {
                        sgt.upd(1, 0, cnt - 1, ump[e.first], e.second);
                    }
                }
                curWidth = envelopes[i][0];
                tmp.clear();
                tmp.push_back(envelopes[i][1]);
            } else {
                tmp.push_back(envelopes[i][1]);
            }
        }
        unordered_map<int, int> buff;
        for (auto e : tmp) {
            int idx = lower_bound(heights.begin(), heights.end(), e) - heights.begin();
            buff[e] = 1;
            if (idx) buff[e] = sgt.get(1, 0, cnt - 1, 0, idx - 1) + 1;
        } 
        for (auto e : buff) {
            sgt.upd(1, 0, cnt - 1, ump[e.first], e.second);
        }

        int ans = 1;
        for (int i = 0; i < cnt; i++) {
            ans = max(ans, sgt.get(1, 0, cnt - 1, i, i));
        }
        return ans;
    }
};