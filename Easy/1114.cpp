class Foo {
private:
    int cur = 1;
    condition_variable cv;
    mutex mtx;
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&] { return cur == 1; } );
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cur++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&] { return cur == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cur++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&] { return cur == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        cur++;
        cv.notify_all();
    }
};