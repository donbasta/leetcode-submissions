class CustomStack {
public:
    int mx;
    vector<int> ve;

    CustomStack(int maxSize) {
        mx = maxSize;        
    }
    
    void push(int x) {
        if (ve.size() < mx) ve.push_back(x);
    }
    
    int pop() {
        if (ve.empty()) return -1;
        int ret = ve.back();
        ve.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k; i++) {
            if (i >= ve.size()) break;
            ve[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */