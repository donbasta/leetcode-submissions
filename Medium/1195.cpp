class FizzBuzz {
private:
    int n;
    int cur;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->cur = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (cur <= n) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return (cur > n || (cur % 3 == 0 && cur % 5 != 0)); });
            // if (cur > n) break;
            if (cur <= n) printFizz(), cur++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (cur <= n) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return (cur > n || (cur % 5 == 0 && cur % 3 != 0)); });
            // if (cur > n) break;
            if (cur <= n) printBuzz(), cur++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (cur <= n) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return (cur > n || (cur % 3 == 0 && cur % 5 == 0)); });
            // if (cur > n) break;
            if (cur <= n) printFizzBuzz(), cur++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (cur <= n) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return (cur > n || (cur % 3 != 0 && this->cur % 5 != 0)); });
            // // if (cur > n) break;
            // cout << cur << '\n';
            if (cur <= n) printNumber(cur), cur++;
            cv.notify_all();
        }
    }
};

// class FizzBuzz {
// private:
//     int n;
//     mutex m;
//     condition_variable c;
//     int i;

// public:
//     FizzBuzz(int n) {
        
//         this->n = n;
//         this->i=1;
//     }

//     // printFizz() outputs "fizz".
//     void fizz(function<void()> printFizz) {
//         while(i<=n)
//         {
//             unique_lock<mutex>lock(m);
//             // while(i<=n && (((i%3)==0) && ((i%5)!=0))==0){
//             //     c.wait(lock);
//             // }
//             c.wait(lock, [&]{return (i > n || (i%3 == 0 && i%5 == 0)));
//             if(i<=n){
//                 printFizz();
//                 ++i;
//             }
//             c.notify_all();
//         }
        
//     }

//     // printBuzz() outputs "buzz".
//     void buzz(function<void()> printBuzz) {
//         while(i<=n)
//         {
//             unique_lock<mutex>lock(m);
//             // while(i<=n && (((i%5)==0) && ((i%3)!=0))==0){
//             //     c.wait(lock);
//             // }
//             c.wait(lock, [&]{return (i<=n && (((i%5)==0) && ((i%3)!=0))==0);});
//             if(i<=n){
//                 printBuzz();
//                 ++i;
//             }
//             c.notify_all();
//         }
//     }

//     // printFizzBuzz() outputs "fizzbuzz".
// 	void fizzbuzz(function<void()> printFizzBuzz) {
//         while(i<=n)
//         {
//             unique_lock<mutex>lock(m);
//             while(i<=n && (((i%5)==0) && ((i%3)==0))==0){
//                 c.wait(lock);
//             }
//             c.wait(lock, [&]{return (i<=n && (((i%3)==0) && ((i%5)==0))==0);});
//             if(i<=n){
//                 printFizzBuzz();
//                 ++i;
//             }
//             c.notify_all();
//         }
//     }

//     // printNumber(x) outputs "x", where x is an integer.
//     void number(function<void(int)> printNumber) {
//         while(i<=n)
//         {
//             unique_lock<mutex>lock(m);
//             while(i<=n && (((i%5)!=0) && ((i%3)!=0))==0){
//                 c.wait(lock);
//             }
//             if(i<=n){
//                 printNumber(i++);
                
//             }
//             c.notify_all();
//         }
//     }
// };