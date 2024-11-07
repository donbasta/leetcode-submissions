class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> lol;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        _k = k;
        for (int i = 0; i < min((int)nums.size(), k); i++) {
            lol.push(nums[i]);
        }
    }
    
    int add(int val) {
        if (lol.size() < _k) lol.push(val);
        else if (lol.top() < val) {
            lol.pop(), lol.push(val);
        }
        return lol.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */