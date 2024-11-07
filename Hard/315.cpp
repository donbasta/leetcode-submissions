class BIT {
public:
    vector<int> ve;
    int _n;
    BIT(int n) {
        ve.resize(n + 1);
        _n = n;
    }
    void upd(int x, int val) {
        while (x <= _n) {
            ve[x] += val;
            x += x & (-x);
        }
    }
    int get(int x) {
        int ret = 0;
        while (x > 0) {
            ret += ve[x];
            x -= x & (-x);
        }
        return ret;
    }
    int get(int x, int y) {
        return get(y) - get(x - 1);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> compressed = nums;
        sort(compressed.begin(), compressed.end());
        compressed.resize(unique(compressed.begin(), compressed.end()) - compressed.begin());
        unordered_map<int, int> umap;
        for (int i = 0; i < compressed.size(); i++) {
            umap[compressed[i]] = i + 1;
        }
        BIT bit(compressed.size());
        vector<int> counts(n);
        for (int i = n - 1; i >= 0; i--) {
            counts[i] = bit.get(umap[nums[i]] - 1);
            bit.upd(umap[nums[i]], 1);
        }
        return counts;
    }
};