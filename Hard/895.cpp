class FreqStack {
public:
    map<int, vector<int>> pos;
    priority_queue<tuple<int, int, int>> pq;
    int curIndex;
    
    FreqStack() {
        curIndex = 0;
    }
    
    void push(int val) {
        pos[val].push_back(curIndex);
        pq.emplace(pos[val].size(), curIndex, val);
        curIndex++;        
    }
    
    int pop() {
        auto lol = pq.top();
        pq.pop();
        int val = get<2>(lol);
        pos[val].pop_back();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */