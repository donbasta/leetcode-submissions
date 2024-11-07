class MyCalendarThree {
public:
    map<int, int> in, out;
    set<int> ckpt;

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        in[startTime]++, out[endTime]++;
        ckpt.insert(startTime), ckpt.insert(endTime);
        int ret = 0;
        int ans = 0;
        for (auto e : ckpt) {
            ret -= out[e];
            ret += in[e];
            ans = max(ans, ret);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */