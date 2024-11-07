class NumArray {
public:
    vector<int> bit, ar;
    int _n;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        _n = n;
        bit.resize(n + 1);
        ar.resize(n);
        for (int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        index += 1;
        int change = val - ar[index - 1];
        ar[index - 1] = val; 
        while (index <= _n) {
            bit[index] += change;
            index += index & (-index);
        }
    }

    int sum(int index) {
        int ret = 0;
        while (index > 0) {
            ret += bit[index];
            index -= index & (-index);
        }
        return ret;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */