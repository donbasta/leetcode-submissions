struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n) {
        tree.resize(n + 1);
    }
    void upd(int idx, int add) {
        while (idx <= n) {
            tree[idx] += add;
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i; 
        }
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        BIT bit(n);
        bit.upd(pos[cp[0]] + 1, 1);
        long long ans = pos[cp[0]] + 1;
        for (int i = 1; i < n; i++) {
            int now = pos[cp[i]] + 1;
            int prv = pos[cp[i - 1]] + 1;
            if (now >= prv) {
                ans += (now - prv) - (bit.get(now) - bit.get(prv));
            } else {
                ans += (n - prv) - (bit.get(n) - bit.get(prv));
                ans += (now) - (bit.get(now));
            }
            bit.upd(now, 1);
        }
        return ans;
    }
};