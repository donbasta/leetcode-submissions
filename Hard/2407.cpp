struct Segtree {
    vector<int> ve;
    Segtree(int n) {ve.resize(4 * n + 5);}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) { ve[v] = val; return; }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else if (idx >= mid + 1) upd(v << 1 | 1, mid + 1, e, idx, val);
        ve[v] = max(ve[v << 1], ve[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return ve[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        vector<int> bruh = nums;
        sort(bruh.begin(), bruh.end());
        bruh.resize(unique(bruh.begin(), bruh.end()) - bruh.begin());
        
        int ans = 0;
        
        unordered_map<int, int> ump;
        int cnt = 0;
        for (auto e : bruh) ump[e] = cnt++;
        Segtree sgt(cnt);
        sgt.upd(1, 0, cnt - 1, ump[nums[0]], 1);
        for (int i = 1; i < nums.size(); i++) {
            int idx_bwh = lower_bound(bruh.begin(), bruh.end(), nums[i] - k) - bruh.begin();
            int mx = 1;
            if (idx_bwh < ump[nums[i]]) {
                mx = sgt.get(1, 0, cnt - 1, idx_bwh, ump[nums[i]] - 1) + 1;
            }
            sgt.upd(1, 0, cnt - 1, ump[nums[i]], mx);
        }
        
        for (int i = 0; i < cnt; i++) {
            ans = max(ans, sgt.get(1, 0, cnt - 1, i, i));
        }
        return ans;
    }
};