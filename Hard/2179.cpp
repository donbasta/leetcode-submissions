struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n) {tree.resize(n + 1);}
    void upd(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    int get(int idx) { 
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> tmp;
        int n = nums1.size();
        vector<int> pos1(n), pos2(n);
        for (int i = 0; i < n; i++) pos1[nums1[i]] = i;
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;
        for (int i = 0; i < n; i++) tmp.emplace_back(pos2[i] + 1, pos1[i] + 1);
        sort(tmp.begin(), tmp.end());

        BIT bit(n);
        bit.upd(tmp[0].second, 1);
        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int kiri = bit.get(tmp[i].second - 1);
            int kanan = n - i - tmp[i].second + kiri;
            ans += 1ll * kiri * kanan;
            bit.upd(tmp[i].second, 1);
        }

        return ans;
    }
};