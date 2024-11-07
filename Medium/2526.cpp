class DataStream {
public:
    int cnt = 0;
    int cnt_last = 0;
    int val_last = -1;
    int check;
    int must;
    DataStream(int value, int k) {
        check = value, must = k;
    }

    bool consec(int num) {
        if (num != val_last) {
            val_last = num;
            cnt_last = 1;
        } else {
            cnt_last++;
        }
        cnt++;
        if (cnt < must) return false;
        return ((cnt_last >= must) && (val_last == check));
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */