struct Vertex {
    int s, e, val;
    bool lz = false;
    Vertex *left = nullptr, *right = nullptr;

    Vertex(int s, int e) : s(s), e(e), val(0) {}

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
        left->lz = right->lz = true;
        left->val += val, right->val += val;
        lz = false;
        val = 0;
    }

    void upd(int l, int r) {
        if (s == l && e == r) {
            val++;
            lz = true;
            return;
        }
        extend();
        push();
        int mid = (s + e) >> 1;
        if (r <= mid) left->upd(l, r);
        else if (l >= mid + 1) right->upd(l, r);
        else {
            left->upd(l, mid);
            right->upd(mid + 1, r);
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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        const int MX = 1e9;
        Vertex* sgt = new Vertex(0, MX - 1);
        for (auto e : flowers) {
            sgt->upd(e[0] - 1, e[1] - 1);
        }
        vector<int> ve;
        for (auto e : persons) {
            ve.push_back(sgt->get(--e));
        }
        return ve;
    }
};