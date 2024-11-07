struct BIT {
    vector<int> tree;
    int _n;
    BIT(int n) : _n(n) {
        tree.resize(n + 1);
    }
    void upd(int idx, int val) {
        while (idx <= _n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    long long get(int idx) {
        long long ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
    long long get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        long long local = 0;
        long long global = 0;
        for (int i = 1; i < n; i++) {
            local += nums[i - 1] > nums[i]; 
        }

        BIT bit(n + 1);

        for (int i = 0; i < n; i++) {
            global += bit.get(nums[i] + 2, n);
            bit.upd(nums[i] + 1, 1);
        }

        return local == global;
    }
};