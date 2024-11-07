class FrontMiddleBackQueue {
private:
    deque<int> d1, d2;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        d1.push_front(val);
        if (d1.size() > d2.size() + 1) {
            int e = d1.back();
            d1.pop_back();
            d2.push_front(e);
        }
    }
    
    void pushMiddle(int val) {
        if (d1.size() == d2.size()) {
            d1.push_back(val);
        } else {
            int e = d1.back();
            d1.pop_back();
            d2.push_front(e);
            d1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        d2.push_back(val);
        if (d2.size() > d1.size()) {
            int e = d2.front();
            d2.pop_front();
            d1.push_back(e);
        }
    }
    
    int popFront() {
        if (d1.empty()) return -1;
        int f = d1.front();
        d1.pop_front();
        if (d1.size() < d2.size()) {
            int e = d2.front();
            d2.pop_front();
            d1.push_back(e);
        }
        return f;
    }
    
    int popMiddle() {
        if (d1.empty()) return -1;
        int b = d1.back();
        d1.pop_back();
        if (d1.size() < d2.size()) {
            int e = d2.front();
            d2.pop_front();
            d1.push_back(e);
        }
        return b;
    }
    
    int popBack() {
        if (d2.empty()) {
            if (d1.empty()) return -1;
            int x = d1.back();
            d1.pop_back();
            return x;
        }
        int b = d2.back();
        d2.pop_back();
        if (d1.size() > d2.size() + 1) {
            int e = d1.back();
            d1.pop_back();
            d2.push_front(e);
        }
        return b;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */