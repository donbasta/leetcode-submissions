struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n) {
        tree.resize(n + 1);
    }
    void upd(int idx, int val) {
        while (idx <= n) {
            tree[idx] = max(tree[idx], val);
            idx += idx & (-idx);
        }
    }
    int get(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret = max(ret, tree[idx]);
            idx -= idx & (-idx);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> T = obstacles;
        sort(T.begin(), T.end());
        T.resize(unique(T.begin(), T.end()) - T.begin());
        int idx = 0;
        unordered_map<int, int> cmp;
        for (auto t : T) cmp[t] = ++idx;
        BIT bit(idx);
        vector<int> ret;
        for (auto e : obstacles) {
            int h = bit.get(cmp[e]);
            ret.push_back(h + 1);
            bit.upd(cmp[e], h + 1);
        }
        return ret;
    }
};