class MyStack {
public:
    vector<queue<int>> q;
    int cur = 0;
    MyStack() {
        q.resize(2);
    }
    
    void push(int x) {
        q[cur].push(x);
    }
    
    int pop() {
        int ans = 0;
        while (!q[cur].empty()) {
            if (q[cur].size() > 1) {
                q[cur ^ 1].push(q[cur].front());
            } else {
                ans = q[cur].front();
            }
            q[cur].pop();
        }
        cur ^= 1;
        return ans;
    }
    
    int top() {
        int ans = 0;
        while (!q[cur].empty()) {
            if (q[cur].size() == 1) {
                ans = q[cur].front();   
            }
            q[cur ^ 1].push(q[cur].front());
            q[cur].pop();
        }
        cur ^= 1;
        return ans;
    }
    
    bool empty() {
        return q[cur].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */