class DiningPhilosophers {
private:
    mutex mtx[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int id,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		if (id == 4) {
            lock_guard<mutex> g1(mtx[0]);
            pickLeftFork();
            lock_guard<mutex> g2(mtx[4]);
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
        } else {
            lock_guard<mutex> g1(mtx[id]);
            pickRightFork();
            lock_guard<mutex> g2(mtx[id + 1]);
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
        }
    }
};