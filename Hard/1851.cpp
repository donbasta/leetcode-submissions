struct Vertex {
    int s, e, val;
    bool lz = false;
    Vertex *left = nullptr, *right = nullptr;

    Vertex(int s, int e) : s(s), e(e), val(int(2e9)) {}

    bool is_leaf() {return s == e;}

    void extend() {
        if (!left && s + 1 <= e) {
            int mid = (s + e) >> 1;
            left = new Vertex(s, mid);
            right = new Vertex(mid + 1, e);
        }
    }

    void push() {
        if (!lz) return;
        if (is_leaf()) return;
        lz = false;
        left->lz = right->lz = true;
        left->val = right->val = val;
    }

    void upd(int l, int r, int new_val) {
        if (s == l && e == r) {
            val = new_val;
            lz = true;
            return;
        }
        extend();
        push();
        int mid = (s + e) >> 1;
        if (r <= mid) left->upd(l, r, new_val);
        else if (l >= mid + 1) right->upd(l, r, new_val);
        else {
            left->upd(l, mid, new_val);
            right->upd(mid + 1, r, new_val);
        }
    }

    int get(int idx) {
        if (s == e) return val;
        extend();
        push();
        int mid = (s + e) >> 1;
        if (idx <= mid) return left->get(idx);
        return right->get(idx);
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, pair<int, int>>> bruh;
        for (auto e : intervals) {
            int l = e[0], r = e[1];
            --l, --r;
            bruh.emplace_back(r - l + 1, make_pair(l, r));
        }
        sort(bruh.begin(), bruh.end(), greater<>());
        const int N = 1e7;
        const int INF = 2e9;
        Vertex* sgt = new Vertex(0, N - 1);
        for (auto e : bruh) {
            int l = e.second.first, r = e.second.second;
            int len = e.first;
            sgt->upd(l, r, len);
        }
        vector<int> ans;
        for (auto e : queries) {
            e--;
            int mn = sgt->get(e);
            if (mn == INF) {
                ans.push_back(-1);
            } else {
                ans.push_back(mn);
            }
        }
        return ans;
    }
};