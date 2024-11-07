class MyCircularDeque {
private:
    int sz, head, tail;
    vector<int> T;
public:
    MyCircularDeque(int k) : sz(k) {
        T.resize(k);
        head = 0, tail = -1;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            T[head] = value;
            tail = (head + 1) % sz;
            return true;
        }
        head = (head + sz - 1) % sz;
        T[head] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            T[head] = value;
            tail = (head + 1) % sz;
            return true;
        }
        T[tail] = value;
        tail = (tail + 1) % sz;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % sz;
        if (head == tail) {
            head = 0, tail = -1;
        }
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail + sz - 1) % sz;
        if (head == tail) {
            head = 0, tail = -1;
        }
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return T[head];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return T[(tail + sz - 1) % sz];
    }
    
    bool isEmpty() {
        return tail == -1;
    }
    
    bool isFull() {
        return head == tail;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */