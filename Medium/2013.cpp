class DetectSquares {
public:
    vector<unordered_map<int, int>> cnt;
    DetectSquares() {
        cnt.resize(1001);
    }
    
    void add(vector<int> point) {
        cnt[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int ret = 0;
        for (auto e : cnt[point[1]]) {
            int x = e.first;
            if (x == point[0]) continue;
            int len = abs(x - point[0]);
            if (point[1] + len <= 1000) {
                ret += cnt[point[1] + len][point[0]] * cnt[point[1] + len][x] * cnt[point[1]][x];
            }
            if (point[1] - len >= 0) {
                ret += cnt[point[1] - len][point[0]] * cnt[point[1] - len][x] * cnt[point[1]][x];
            }
        }
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */