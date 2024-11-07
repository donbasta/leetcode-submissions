class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        using ll = long long;
        struct Node {
            int p, q, r, s;
            Node() {}
            Node(ll val) : p(0), q(0), r(0), s(max(0ll, val)) {}
        };
        auto merge = [&](Node& p, Node& q) -> Node {
            Node ret;
            ret.p = max(p.p + q.r, p.q + q.p);
            ret.q = max(p.p + q.s, p.q + q.q);
            ret.r = max(p.s + q.p, p.r + q.r);
            ret.s = max(p.s + q.q, p.r + q.s);
            return ret;
        };
        vector<Node> ve(4 * n + 5);

        function<void(int, int, int)> build = [&](int v, int s, int e) {
            if (s == e) {
                ve[v] = Node(nums[s]);
                return;
            }
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            ve[v] = merge(ve[v << 1], ve[v << 1 | 1]);
        };
        function<void(int, int, int, int, int)> upd = [&](int v, int s, int e, int idx, ll val) {
            if (s == e) {
                ve[v] = Node(val);
                return;
            }
            int mid = (s + e) >> 1;
            if (idx <= mid) upd(v << 1, s, mid, idx, val);
            else if (idx >= mid + 1) upd(v << 1 | 1, mid + 1, e, idx, val);
            ve[v] = merge(ve[v << 1], ve[v << 1 | 1]);
        };

        build(1, 0, n - 1);
        ll ans = 0;
        const ll MOD = 1e9 + 7;
        for (auto q : queries) {
            upd(1, 0, n - 1, q[0], q[1]);
            ans = (ans + ve[1].s) % MOD;
        }
        if (ans < 0) ans += MOD;
        return ans;
    }
};