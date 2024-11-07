class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        int n = gas.size();
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            val[i] = cur;
            cur += gas[i];
            cur -= cost[i];
        }
        if (cur < 0) return -1;
        int idx = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (val[i] < mn) {
                mn = val[i];
                idx = i;
            }
        }
        return idx;
    }
};