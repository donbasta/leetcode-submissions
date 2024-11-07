class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> ev;
        for (auto t : trips) {
            ev[t[1]] += t[0];
            ev[t[2]] -= t[0];
        }
        int cur = 0;
        for (auto e : ev) {
            cur += e.second;
            if (cur > capacity) return false;
        }
        return true;
    }
};