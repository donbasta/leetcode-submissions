class H2O {
private:
    mutex m;
    condition_variable cv;
    int h_need = 2, o_need = 1;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&] { return h_need > 0; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h_need--;
        if (h_need == 0 && o_need == 0) {
            h_need = 2, o_need = 1;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&] { return o_need > 0; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o_need--;
        if (o_need == 0 && h_need == 0) {
            h_need = 2, o_need = 1;
        }
        cv.notify_all();
    }
};