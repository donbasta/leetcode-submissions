class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> ret;
        int t = 1;
        while (true) {
            if (max(memory1, memory2) < t) {
                ret.push_back(t);
                ret.push_back(memory1);
                ret.push_back(memory2);
                return ret;
            }
            if (memory1 >= memory2) {
                memory1 -= t;
            } else {
                memory2 -= t;
            }
            t++;
        }
        return ret;
    }
};