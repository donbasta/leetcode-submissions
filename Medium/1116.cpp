class ZeroEvenOdd {
private:
    int n, cur;
    condition_variable cv;
    bool zero_time;
    mutex mtx;

public:
    ZeroEvenOdd(int n) {
        this->cur = 1;
        this->n = n;
        this->zero_time = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(this->mtx);
            cv.wait(lock, [&] { return this->zero_time; });
            if (this->cur > this->n) break;
            printNumber(0);
            this->zero_time = false;
            this->cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 0; i < n / 2; i++) {
            unique_lock<mutex> lock(this->mtx);
            cv.wait(lock, [&] { return !this->zero_time && (this->cur % 2 == 0); });
            if (this->cur > this->n) break;
            printNumber(this->cur);
            this->cur++;
            this->zero_time = true;
            this->cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 0; i < (n + 1) / 2; i++) {
            unique_lock<mutex> lock(this->mtx);
            cv.wait(lock, [&] { return !this->zero_time && (this->cur % 2 == 1); });
            if (this->cur > this->n) break;
            printNumber(this->cur);
            this->cur++;
            this->zero_time = true;
            this->cv.notify_all();
        }
    }
};