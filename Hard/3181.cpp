class Solution {
public:
    int maxTotalReward(vector<int>& val) {
        int n = val.size();
        sort(val.begin(), val.end());
        int M = 1e5;
    
        bitset<100005> bt;
        bt[0] = true;
        bt[val[0]] = true;

        bitset<100005> cur;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            while (idx < val[i]) {
                cur[idx++] = 1;
            }
            bt |= ((bt & cur) << val[i]);
        }
        for (int i = M; i >= 0; i--) {
            if (bt[i]) return i;
        }
        return -1;   
    }
};