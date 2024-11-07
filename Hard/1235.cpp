class Segtree {
   public:
    vector<int> tree;
    int n;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else if (idx >= mid + 1) upd(v << 1 | 1, mid + 1, e, idx, val);
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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> tmp;
        for (auto e : startTime) tmp.push_back(e);
        for (auto e : endTime) tmp.push_back(e);
        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
        int cnt = 0;
        unordered_map<int, int> compress;
        vector<int> lmao = {0};
        for (auto e : tmp) compress[e] = ++cnt, lmao.push_back(e);

        vector<tuple<int, int, int>> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) -> bool {
            return get<1>(a) < get<1>(b);
        });
        vector<int> dp(cnt + 5);
        Segtree sgt(cnt + 5);
        for (int i = 0; i < n; i++) {
            int start = get<0>(jobs[i]);
            int end = get<1>(jobs[i]);
            int pr = get<2>(jobs[i]);
            dp[compress[end]] = max(dp[compress[end]], pr + sgt.get(1, 0, cnt, 0, compress[start]));
            sgt.upd(1, 0, cnt, compress[end], dp[compress[end]]);
        }
        int ans = 0;
        for (int i = 0; i <= cnt; i++) {
            ans = max(ans, dp[i]); 
        }
        return ans;
    }
};