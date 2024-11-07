class DinnerPlates {
public:
    const int M = 2e5;
    // stack<int> ve[200000 + 1];
    vector<stack<int>> ve;
    set<int> nonempty, nonfull;
    int mex, cap, mx_sz;
    DinnerPlates(int capacity) {
        mx_sz = M / capacity;
        ve.resize(mx_sz + 1);
        mex = 0;
        cap = capacity;
        for (int i = 0; i <= mx_sz; i++) nonfull.insert(i);
    }

    void push(int val) {
        ve[mex].push(val);
        if (ve[mex].size() == 1) nonempty.insert(mex);
        if (ve[mex].size() == cap) {
            nonfull.erase(mex);
            mex = *nonfull.begin();
        }
    }

    int pop() {
        if (nonempty.empty()) return -1;
        int ri = *nonempty.rbegin();
        int ret = ve[ri].top();
        ve[ri].pop();
        if (ve[ri].empty()) nonempty.erase(ri);
        if (ve[ri].size() == cap - 1) {
            nonfull.insert(ri);
            if (ri < mex) mex = ri;
        }
        return ret;
    }

    int popAtStack(int index) {
        if (ve[index].empty()) return -1;
        int ret = ve[index].top();
        ve[index].pop();
        if (ve[index].empty()) nonempty.erase(index);
        if (ve[index].size() == cap - 1) {
            nonfull.insert(index);
            if (index < mex) mex = index;
        }
        return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */