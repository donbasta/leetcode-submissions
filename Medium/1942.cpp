class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        map<int, vector<int>> a, b;
        int n = times.size();
        set<int> se, avail;
        for (int i = 0; i < n; i++) avail.insert(i);
        vector<int> pos(n, -1);
        for (int i = 0; i < n; i++) {
            a[times[i][0]].push_back(i);
            b[times[i][1]].push_back(i);
            se.insert(times[i][0]);
            se.insert(times[i][1]);
        }
        for (auto t : se) {
            if (b.count(t)) {
                for (auto bb : b[t]) avail.insert(pos[bb]);
            }
            if (a.count(t)) {
                for (auto aa : a[t]) {
                    pos[aa] = *avail.begin();
                    avail.erase(avail.begin());
                }
            }
        }
        return pos[targetFriend];
    }
};