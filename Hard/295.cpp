class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int kiri = left.size();
        int kanan = right.size();
        if (kiri == 0 && kanan == 0) {
            left.push(num);
            return;
        }
        if (kiri == kanan) {
            if (num <= right.top()) {
                left.push(num);
            } else if (num > right.top()) {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        } else {
            assert (kiri == kanan + 1);
            if (num < left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        int kiri = left.size();
        int kanan = right.size();
        if (kiri == kanan) {
            return (double) (left.top() + right.top()) / 2.0;
        } 
        assert (kiri == kanan + 1);
        return (double) (left.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */