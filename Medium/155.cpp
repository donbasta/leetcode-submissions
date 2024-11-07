class MinStack {
public:
    stack<pair<int, int>> st;
    stack<pair<int, int>> mst;
    int t = 0;

    MinStack() {}
    
    void push(int val) {
        st.push(make_pair(val, t));
        if (mst.empty()) {
            mst.push(make_pair(val, t));
        } else {
            if (val < mst.top().first) {
                mst.push(make_pair(val, t));
            }
        }
        t++;
    }

    void pop() {
        int popped_t = st.top().second;
        st.pop();
        if (mst.top().second == popped_t) {
            mst.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mst.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */